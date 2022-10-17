document.getElementById("generate").addEventListener("click", generate);

function generate() {
    var Length = document.getElementById('length').value;
    var length = parseInt(Length);
    console.log(length);
    const display = document.getElementById("password");

    if (length < 5) {
        display.innerHTML = "Password length is too small, please enter a length between 5 - 50";
    }
    else if (length > 50) {
        display.innerHTML = "Password length is too large, please enter a length between 5 - 50";
    }
    else {
        //Declaring Empty String
        var password = "";

        //With the help of these objects we'll create our password
        var alphabet_lower = "abcdefghijklmnopqrstuvwxyz";
        var alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        var symbols = "!@#$%&";
        var number = "0123456789";

        //Ineger objects
        var key, count_alpha_lwr = 0, count_alpha_uppr = 0, count_symbols = 0, count_number = 0;

        var c = 0;
        while (c < length) {
            var k = Math.floor(Math.random() * 4) + 1;   //Generates a Random Number between 1 to 4

            if (c == 0) {
                k %= 3;
                if (k == 0)
                    ++k;
            }
            switch (k) {
                case 1:/*This block will help to add lowercase alphabets in the password*/{
                    if ((count_alpha_lwr == 2) && (count_number == 0 || count_alpha_uppr == 0 || count_alpha_uppr == 1 || count_symbols == 0))
                        break;
                    var key = Math.floor(Math.random() * 26);
                    password = password + alphabet_lower[key];
                    count_alpha_lwr++;
                    c++;
                    break;
                }

                case 2:/*This block will help to add uppercase alphabets in the password*/{
                    if ((count_alpha_uppr == 2) && (count_number == 0 || count_alpha_lwr == 0 || count_alpha_lwr == 1 || count_symbols == 0))
                        break;
                    key = Math.floor(Math.random() * 26);
                    password = password + alphabet_upper[key];
                    count_alpha_uppr++;
                    c++;
                    break;
                }
                case 3:/*This block will help to add digits in the password*/{
                    if ((count_number == 1) && (count_alpha_lwr == 0 || count_alpha_lwr == 1 || count_alpha_uppr == 1 || count_alpha_uppr == 0 || count_symbols == 0))
                        break;
                    key = Math.floor(Math.random() * 10);
                    password = password + number[key];
                    count_number++;
                    c++;
                    break;
                }
                case 4:/*This block will help to symbols in the password*/{
                    if ((count_symbols == 1) && (count_alpha_lwr == 0 || count_alpha_lwr == 0 || count_alpha_lwr == 1 || count_alpha_uppr == 0 || count_alpha_uppr == 1 || count_number == 0))
                        break;
                    key = Math.floor(Math.random() * 6);
                    password = password + symbols[key];
                    count_symbols++;
                    c++;
                    break;
                }
            }
        }
        display.innerHTML = password;
    }
}