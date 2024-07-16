#include "BitcoinExchange.cpp"

static void convert(const std::string& filename, std::map<std::string, double> data)
{
    std::string line;
    std::ifstream file(filename.c_str());
    std::string date;
    std::string value_string;
    double value;
    char *end;
    double result;

    if (!file.is_open()) {
        throw std::runtime_error("Can't open file!");
    }

    std::getline(file, line);
    while (std::getline(file, line)){
        if (parsing_input(line)) {
            date = line.substr(0, 10);
            value_string = line.substr(13);
            value = std::strtod(value_string.c_str(), &end);
            
            std::string date_closest = find_closest_date(data, date);
            if (!date_closest.empty()){
                result = data.at(date_closest) * value;
                std::cout << date_closest 
                          << " -> " << value 
                          << " -> " << data.at(date_closest) 
                          << " = " << result << std::endl;
            }         
        }
    }
    file.close();
}

int main(int ac, char ** av)
{
    if (ac != 2){
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    std::string file = "data.csv";

    try{
        std::map<std::string, double> data = read_csv(file);
        if (data.empty()) {
            std::cerr << "Error: data map is empty. Check the input file." << std::endl;
            return (2);
        }

        convert(av[1], data);
    } catch (std::runtime_error &e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}