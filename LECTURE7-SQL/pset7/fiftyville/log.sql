-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports WHERE year = 2023 AND month = 07 AND day = 28 AND street = 'Humphrey Street';  -- id 295, Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery

SELECT * FROM bakery_security_logs WHERE year = 2023 AND month = 07 AND day = 28 AND hour = 10;

SELECT * FROM interviews WHERE year = 2023 AND month = 07 AND day = 28;

SELECT * FROM atm_transactions WHERE year = 2023 AND month = 07 AND day = 28 AND atm_location = 'Leggett Street';

SELECT * FROM phone_calls WHERE year = 2023 AND month = 07 AND day = 28 AND duration < 60;

SELECT * FROM airports WHERE city = 'Fiftyville';

SELECT * FROM flights WHERE year = 2023 AND month = 07 AND day = 29 AND origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') ORDER BY hour ASC, minute ASC LIMIT 1; -- Flight ID

SELECT * FROM airports WHERE id = 4; -- New York City

SELECT * FROM passengers JOIN people ON people.passport_number = passengers.passport_number WHERE flight_id = 36;

SELECT * FROM bakery_security_logs WHERE year = 2023 AND month = 07 AND day = 28 AND hour = 10 AND license_plate in (SELECT license_plate FROM passengers JOIN people ON people.passport_number = passengers.passport_number WHERE flight_id = 36);

SELECT * FROM bank_accounts WHERE bank_accounts.person_id IN (SELECT people.id FROM passengers JOIN people ON people.passport_number = passengers.passport_number WHERE flight_id = 36);

SELECT * FROM atm_transactions WHERE year = 2023 AND month = 07 AND day = 28 AND atm_location = 'Leggett Street' AND atm_transactions.account_number IN
(SELECT account_number FROM bank_accounts WHERE bank_accounts.person_id IN (SELECT people.id FROM passengers JOIN people ON people.passport_number = passengers.passport_number WHERE flight_id = 36));

SELECT * FROM people WHERE people.phone_number IN (SELECT caller FROM phone_calls WHERE year = 2023 AND month = 07 AND day = 28 AND duration < 60);

SELECT * FROM people WHERE people.phone_number IN (SELECT caller FROM phone_calls WHERE year = 2023 AND month = 07 AND day = 28 AND duration < 60)
AND people.passport_number IN (SELECT passengers.passport_number FROM passengers JOIN people ON people.passport_number = passengers.passport_number WHERE flight_id = 36)
AND people.license_plate IN (SELECT bakery_security_logs.license_plate FROM bakery_security_logs WHERE year = 2023 AND month = 07 AND day = 28 AND hour = 10 AND license_plate in (SELECT license_plate FROM passengers JOIN people ON people.passport_number = passengers.passport_number WHERE flight_id = 36))
AND people.id IN (SELECT bank_accounts.person_id FROM bank_accounts WHERE bank_accounts.person_id IN (SELECT people.id FROM passengers JOIN people ON people.passport_number = passengers.passport_number WHERE flight_id = 36));

SELECT * FROM people where people.phone_number = (SELECT receiver FROM phone_calls WHERE year = 2023 AND month = 07 AND day = 28 AND duration < 60 AND caller = '(367) 555-5533');
