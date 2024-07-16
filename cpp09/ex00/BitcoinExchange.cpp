#include "BitcoinExchange.hpp"

bool is_double(const char* str) 
{
    if (str == NULL || *str == '\0' || isspace(*str)) {
        return false;
    }

    char* end;
    double val = strtod(str, &end);

    if (*end != '\0'){
        if (isspace(*end)){
            std::cerr << "Don't put any space after the value!" << std::endl;
            return false;
        }
        std::cerr << "Bad input value: " << str << std::endl;
        return false;
    }

    long test_int = static_cast<long>(val);
    if (test_int < 0 || test_int > INT_MAX){
        std::cerr << "Value must be beetween 0 and int max include" << std::endl;
        return false;
    }
    return true;
}

bool is_valid_date(const std::string& date)
{
    if (date[4] != '-' || date[7] != '-' || date.length() != 10){
        std::cerr << "You must print with this format: YYYY-MM-DD" << std::endl;
        return (false);
    }

    int year, month, day;
    if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3) {
        std::cerr << "Wrong Month or Day" << std::endl;
        return false;
    }

    if (month < 1 || month > 12 || day > 31 || day < 1) {
        std::cerr << "Wrong Month or Day" << std::endl;
        return false;
    }
    return true;
}

bool parsing_input(const std::string& line)
{
    if (line.length() < 14 || line.compare(10, 3, " | ") != 0){
        std::cerr << "bad format: " << line << std::endl;
        return false;
    }
    if (!is_valid_date(line.substr(0, 10))) {
        return false;
    }

    if (!is_double(line.c_str() + 13)) {
        return false;
    }
    return true;
}

std::string find_closest_date(const std::map<std::string, double>& data, const std::string& date)
{
    std::map<std::string, double>::const_iterator it = data.lower_bound(date);
    if (it == data.end() || (it != data.begin() && it->first != date)) {
        --it;
    }
    return it->first;
}

std::map<std::string, double> read_csv(const std::string& filename) 
{
    std::string line;
    std::ifstream file(filename.c_str());
    std::map<std::string, double> data;
    double value;

    if (!file.is_open()) {
        throw std::runtime_error("Can't open file!");
    }

    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string block;
        std::string key;
        char* end;

        std::getline(lineStream, block, ',');
        key = block;
        std::getline(lineStream, block, ',');
        value = std::strtod(block.c_str(), &end);

        data[key] = value;
    }

    file.close();
    return (data);
}