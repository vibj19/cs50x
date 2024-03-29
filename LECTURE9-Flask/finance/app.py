import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "GET":
        return render_template ("buy.html")

    elif request.method == "POST":
        shares = request.form.get("shares")
        symbol = request.form.get("symbol")
        if request.form['search'] == 'search':
            stock = lookup(symbol)
            if stock == None or shares == None or symbol == None:
                flash("Error: Could not find stock")
                return redirect("/buy")
            cost = round(float(stock['price']) * int(shares), 2)
            balance = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])[0]['cash']
            return render_template("buy.html", stock=stock, cost=cost, balance=balance)
        elif request.form['buy'] == 'buy':
            if stock == None or shares == None or symbol == None:
                flash("Error: Could not find stock")
                return redirect("/buy")
            cost = round(float(stock['price']) * int(shares), 2)
            balance = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])[0]['cash']
            if cost > balance:
                flash("Error: Cannot afford")
                return redirect("/buy")
            balance = balance - cost
            owned = db.execute("INSERT INTO stocks (user_id, symbol, shares, price, timestamp) VALUES (:user_id, :symbol, :shares, :price, CURRENT_TIMESTAMP)", user_id=session["user_id"], symbol=symbol, shares=shares, price=stock['price'])
            update = db.execute("UPDATE users SET cash = :balance WHERE id= :id", balance=balance, id=session["user_id"])
            return redirect("/buysuccess")

@app.route("/buysuccess", methods=["GET", "POST"])
@login_required
def buysuccess():
    return render_template ("buysuccess.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "GET":
        return render_template("quote.html")
    elif request.method == "POST":
        return render_template("quoted.html")

@app.route("/quoted", methods=["GET", "POST"])
@login_required
def quoted():
    if request.method == "GET":
        return render_template("quote.html")
    elif request.method == "POST":
        symbol = request.form.get("symbol")
        stock = lookup(symbol)
        if stock == None:
            flash("Error: Could not find stock")
            return redirect("/quote")
        else:
            return render_template("quoted.html", stock=stock)


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("register.html")
    elif request.method == "POST":
        username = request.form.get("username")
        dupecheck = db.execute("SELECT username FROM users")
        regflag = False
        for i in dupecheck:
            if username == i['username']:
                regflag = True
        if regflag == True:
                return "Error: Could not register user"
        else:
            password = generate_password_hash(request.form.get("password"))
            entry = db.execute ("INSERT INTO users (username, hash) VALUES (?, ?)", username, password)
            if entry is None:
                return "Error: Could not register user"
        return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")

