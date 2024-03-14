#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round((originalRed * .393) + (originalGreen * .769) + (originalBlue * .189));
            int sepiaGreen = round((originalRed * .349) + (originalGreen * .686) + (originalBlue * .168));
            int sepiaBlue = round((originalRed * .272) + (originalGreen * .534) + (originalBlue * .131));

            if (sepiaRed < 255)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }

            if (sepiaGreen < 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            if (sepiaBlue < 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2.0; j++)
        {
            int swapred = image[i][j].rgbtRed;
            int swapblue = image[i][j].rgbtBlue;
            int swapgreen = image[i][j].rgbtGreen;

            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;

            image[i][width - 1 - j].rgbtRed = swapred;
            image[i][width - 1 - j].rgbtBlue = swapblue;
            image[i][width - 1 - j].rgbtGreen = swapgreen;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            // top left corner
            if (i == 0 && j == 0)
            {
                int accred = 0;
                int accblue = 0;
                int accgreen = 0;

                for (int row = 0; row < 2; row++)
                {
                    for (int col = 0; col < 2; col++)
                    {
                        accred += copy[i + row][j + col].rgbtRed;
                        accblue += copy[i + row][j + col].rgbtBlue;
                        accgreen += copy[i + row][j + col].rgbtGreen;
                    }
                }
                image[i][j].rgbtRed = round(accred / 4.0);
                image[i][j].rgbtBlue = round(accblue / 4.0);
                image[i][j].rgbtGreen = round(accgreen / 4.0);
            }

            // top right corner
            if (i == 0 && j == width - 1)
            {
                int accred = 0;
                int accblue = 0;
                int accgreen = 0;

                for (int row = 0; row < 2; row++)
                {
                    for (int col = -1; col < 1; col++)
                    {
                        accred += copy[i + row][j + col].rgbtRed;
                        accblue += copy[i + row][j + col].rgbtBlue;
                        accgreen += copy[i + row][j + col].rgbtGreen;
                    }
                }
                image[i][j].rgbtRed = round(accred / 4.0);
                image[i][j].rgbtBlue = round(accblue / 4.0);
                image[i][j].rgbtGreen = round(accgreen / 4.0);
            }

            // bottom left corner
            if (i == height - 1 && j == 0)
            {
                int accred = 0;
                int accblue = 0;
                int accgreen = 0;

                for (int row = 0; row < 2; row++)
                {
                    for (int col = 0; col < 2; col++)
                    {
                        accred += copy[i - row][j + col].rgbtRed;
                        accblue += copy[i - row][j + col].rgbtBlue;
                        accgreen += copy[i - row][j + col].rgbtGreen;
                    }
                }
                image[i][j].rgbtRed = round(accred / 4.0);
                image[i][j].rgbtBlue = round(accblue / 4.0);
                image[i][j].rgbtGreen = round(accgreen / 4.0);
            }

            // bottom right corner
            if (i == height - 1 && j == width - 1)
            {
                int accred = 0;
                int accblue = 0;
                int accgreen = 0;

                for (int row = 0; row < 2; row++)
                {
                    for (int col = 0; col < 2; col++)
                    {
                        accred += copy[i - row][j - col].rgbtRed;
                        accblue += copy[i - row][j - col].rgbtBlue;
                        accgreen += copy[i - row][j - col].rgbtGreen;
                    }
                }
                image[i][j].rgbtRed = round(accred / 4.0);
                image[i][j].rgbtBlue = round(accblue / 4.0);
                image[i][j].rgbtGreen = round(accgreen / 4.0);
            }

            // top edge

            if (i == 0 && j > 0 && j < width - 1)
            {
                int accred = 0;
                int accblue = 0;
                int accgreen = 0;

                for (int row = 0; row < 2; row++)
                {
                    for (int col = -1; col < 2; col++)
                    {
                        accred += copy[i + row][j + col].rgbtRed;
                        accblue += copy[i + row][j + col].rgbtBlue;
                        accgreen += copy[i + row][j + col].rgbtGreen;
                    }
                }
                image[i][j].rgbtRed = round(accred / 6.0);
                image[i][j].rgbtBlue = round(accblue / 6.0);
                image[i][j].rgbtGreen = round(accgreen / 6.0);
            }

            // bottom edge

            if (i == height - 1 && j > 0 && j < width - 1)
            {
                int accred = 0;
                int accblue = 0;
                int accgreen = 0;

                for (int row = -1; row < 1; row++)
                {
                    for (int col = -1; col < 2; col++)
                    {
                        accred += copy[i + row][j + col].rgbtRed;
                        accblue += copy[i + row][j + col].rgbtBlue;
                        accgreen += copy[i + row][j + col].rgbtGreen;
                    }
                }
                image[i][j].rgbtRed = round(accred / 6.0);
                image[i][j].rgbtBlue = round(accblue / 6.0);
                image[i][j].rgbtGreen = round(accgreen / 6.0);
            }

            // left edge

            if (j == 0 && i > 0 && i < height - 1)
            {
                int accred = 0;
                int accblue = 0;
                int accgreen = 0;

                for (int row = -1; row < 1; row++)
                {
                    for (int col = 0; col < 2; col++)
                    {
                        accred += copy[i + row][j + col].rgbtRed;
                        accblue += copy[i + row][j + col].rgbtBlue;
                        accgreen += copy[i + row][j + col].rgbtGreen;
                    }
                }
                image[i][j].rgbtRed = round(accred / 6.0);
                image[i][j].rgbtBlue = round(accblue / 6.0);
                image[i][j].rgbtGreen = round(accgreen / 6.0);
            }

            // right edge

            if (j == width - 1 && i > 0 && i < height - 1)
            {
                int accred = 0;
                int accblue = 0;
                int accgreen = 0;

                for (int row = -1; row < 2; row++)
                {
                    for (int col = -1; col < 1; col++)
                    {
                        accred += copy[i + row][j + col].rgbtRed;
                        accblue += copy[i + row][j + col].rgbtBlue;
                        accgreen += copy[i + row][j + col].rgbtGreen;
                    }
                }
                image[i][j].rgbtRed = round(accred / 6.0);
                image[i][j].rgbtBlue = round(accblue / 6.0);
                image[i][j].rgbtGreen = round(accgreen / 6.0);
            }

            // regular
            else
            {
                int accred = 0;
                int accblue = 0;
                int accgreen = 0;

                for (int row = -1; row < 2; row++)
                {
                    for (int col = -1; col < 2; col++)
                    {
                        accred += copy[i + row][j + col].rgbtRed;
                        accblue += copy[i + row][j + col].rgbtBlue;
                        accgreen += copy[i + row][j + col].rgbtGreen;
                    }
                }
                image[i][j].rgbtRed = round(accred / 9.0);
                image[i][j].rgbtBlue = round(accblue / 9.0);
                image[i][j].rgbtGreen = round(accgreen / 9.0);
            }
        }
    }
    return;
}
