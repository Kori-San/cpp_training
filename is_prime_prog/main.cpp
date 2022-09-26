#include <iostream>
#include <list>
#include <string>

using namespace std;

list<int> parse_stdin(string line);
bool is_prime_num(int num);
void print_prime(list<int> num_list);

int main() {
    // * Get input from 'stdin' *
    string line;
    getline(cin, line);

    // * Print list
    list<int> stdin_list = parse_stdin(line);
    print_prime(stdin_list);

    // * End Main
    return 0;
}

list<int> parse_stdin(string line) {
    // * Create tmp string to store numbers and List of int to store them *
    string tmp = "";
    list<int> stdin_list;

    // * Create an int iterator and a string one to loop on input *
    int i;
    string::iterator it;

    // * Loop on input and push back numbers on 'stdin_list' *
    for (it = line.begin(), i = 0; it != line.end(); it++, i++) {
        // * If Delim is reached then push back tmp string as int *
        if (line[i] == ' ') {
            stdin_list.push_back(stoi(tmp));
            tmp = "";
        }

        // * If Char is a digit then add to tmp
        if (line[i] >= '0' && line[i] <= '9')
            tmp += line[i];
    }

    // * Add final number
    stdin_list.push_back(stoi(tmp));
    tmp = "";

    // * Return list
    return stdin_list;
}

bool is_prime_num(int n) {
    // * 2 first prime numbers *
    if (n == 2 || n == 3)
        return true;

    /* If 'n' is inferior or equal to one or he
       can be divided by 2 or 3 then it's not
       a prime number                           */
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    // * If n is divided by something else then he's not prime *
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    // * Default return *
    return true;
}

void print_prime(list<int> num_list) {
    // * Loop over 'num_list' with 'num' and test if 'num' is prime *
    for (int num: num_list) {
        string status = (is_prime_num(num)) ? "True" : "False";
        cout << num << " is a prime: " << status << endl;
    }
}
