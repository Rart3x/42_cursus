#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(void){}

Bitcoin::Bitcoin(const Bitcoin &src){
    if (this != &src)
        *this = src;
}

Bitcoin::~Bitcoin(void){}

Bitcoin& Bitcoin::operator=(const Bitcoin &src){
    if (this != &src)
        return (*this);
    return (*this);
}

void Bitcoin::calculate(std::string _inputLine, std::string _inputValue) {
    std::map<int, std::string>::iterator it;
    std::string _line;
    std::string _csvLine;
    std::string _csvValue;

    std::map<int, std::string> _split;

    std::string closestDate = "";
    float closestValue = 0.0;

    for (it = this->_csv.begin(); it != this->_csv.end(); it++) {
        _line = it->second;
        _split = this->splitAt(_line, ',', false);
        _csvLine = _split[0];
        _csvValue = _split[1];

        if (_csvLine == _inputLine) {
            std::cout << GREEN << _inputLine << " => " << _inputValue << " = " << (std::atof(_inputValue.c_str()) * std::atof(_csvValue.c_str())) << RESET << std::endl;
            return;
        }

        if (_csvLine < _inputLine && _csvLine > closestDate) {
            closestDate = _csvLine;
            closestValue = std::atof(_csvValue.c_str());
        }
    }

    if (!closestDate.empty()) {
        std::cout << GREEN << _inputLine << " => " << _inputValue << " = " << (std::atof(_inputValue.c_str()) * closestValue) << RESET << std::endl;
    }
    else {
        std::cout << RED << "error: no matching or closest date found => " << _inputLine << RESET << std::endl;
    }
}

void    Bitcoin::extractDatas(std::string _filename, bool _isCSV){
    std::ifstream 	_file(_filename.c_str());
    std::string     _line;

    bool            firstLine = true;
    
    if (_isCSV == true){
        while (std::getline(_file, _line)){
            if (firstLine == true){
                firstLine = false;
                continue;
            }
            _line = _line.substr(0, _line.find('\n'));
            if (_line.empty() == false)
                this->_csv.insert(std::pair<int, std::string>(this->_csv.size(), _line));
        }
    }
    else {
        while (std::getline(_file, _line)){
            if (firstLine == true){
                firstLine = false;
                continue;
            }
            _line = _line.substr(0, _line.find('\n'));
            if (_line.empty() == false)
                this->_input.insert(std::pair<int, std::string>(this->_input.size(), _line));
        }
    }
    _file.close();
}

void    Bitcoin::nbArgs(int ac) {
    if (ac != 2)
        this->printError("error: invalid number of arguments", "");
}

void    Bitcoin::program(int ac, char **av){
    this->_endBool = false;
    this->_errorLoopInput = false;
    this->_errorBool = false;
    
    this->nbArgs(ac);
    this->setFilename(av[1]);
    if (!this->verifFiles("data.csv"))
        return;
    if (!this->verifFiles(this->_filename))
        return;
    this->extractDatas("data.csv", true);
    this->extractDatas(this->_filename, false);
    this->verifCSVDatas(this->_csv);
    if (this->_endBool == true)
        return ;
    this->verifInputDatas(this->_input);
}

std::map<int, std::string>  Bitcoin::splitAt(std::string _line, int delim, bool flag){

    size_t  i = 0;
    size_t  start;
    size_t  end = 0;

    std::map<int, std::string>  _split;

    while ((start = _line.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = _line.find(delim, start);
		_split.insert(std::make_pair(i, _line.substr(start, end - start)));
        i++;
        if (!flag){
            if (i == 2)
                break;
        }
        else
            if (i == 3)
               break;
	}
    if ((this->_errorLoopInput == false) && ((!flag && i != 2 ) || (flag && i != 3)))
        this->printError("error: invalid data format", "");
    return (_split);
}

std::string Bitcoin::trim(std::string str) {
    
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isspace(str[i])) {
            break;
        }
        else if (this->_errorLoopInput == false && i == str.length() - 1 && std::isspace(str[i])) {
            this->printError("error: invalid data format", "");
        }
    }

    size_t count = str.find_first_not_of(WHITESPACES);

    size_t firstSpaceAfterSubstr = str.find_first_of(" \t", count);

    if (firstSpaceAfterSubstr != std::string::npos) {
        for (size_t i = firstSpaceAfterSubstr; i < str.length(); i++) {
            if (!std::isspace(str[i])) {
                this->printError("error: contains non-whitespace characters after this line", str);
                break;
            }
        }
    }

    str = str.substr(count);
    str.erase(str.find_last_not_of(WHITESPACES) + 1);

    char lastChar = str[str.length() - 1];
    if (lastChar != ' ' && !isdigit(lastChar))
        this->printError("error: contains invalid characters =>", str);
    return str;
}


void    Bitcoin::verifCSVDatas(std::map<int, std::string> _map){
    
    std::map<int, std::string>  _line;
    std::map<int, std::string>::iterator it;    

    this->_errorBool = false;

    for (it = _map.begin(); it != _map.end(); it++) {
        


        _line = this->splitAt(it->second, '-', false);

        if (this->_errorBool == false && it->second.length() < 12)
            this->printError("error: bad input =>", this->splitAt(it->second, ',', false)[0]);

        _line = splitAt(it->second, ',', false);
        _line[0] = trim(_line[0]);
        _line[1] = trim(_line[1]);

        if (this->_errorBool == false && _line[0].empty())
            this->printError("error: bad input =>", this->splitAt(it->second, ',', false)[0]);

        if (this->_errorBool == false && _line[1].empty())
            this->printError("error: bad input =>", this->splitAt(it->second, ',', false)[0]);

        float _value = atof(_line[1].c_str());

        if (this->_errorBool == false && _value < 0)
            this->printError("error: not a positive number", "");

        if (this->_errorBool == false && (_line[0][4] != '-' || _line[0][7] != '-'))
            this->printError("error: bad input =>", this->splitAt(it->second, ',', false)[0]);

        std::map<int, std::string>  _date = this->splitAt(_line[0], '-', true);

        if (this->_errorBool == false && (_date[0].length() != 4 || _date[1].length() != 2 || _date[2].length() != 2))
            this->printError("error: bad input =>", this->splitAt(it->second, ',', false)[0]);

        if (this->_errorBool == false && (!verifDateDigit(_date[0]) || !verifDateDigit(_date[1]) || !verifDateDigit(_date[2])))
            this->printError("error: bad input =>", this->splitAt(it->second, ',', false)[0]);

        if (this->_errorBool == false && !verifDateConformity(_date))
            this->printError("error bad input =>", trim(this->splitAt(it->second, '|', false)[0]));

        if (this->_errorBool == true){
            this->printError("error: invalid data format in CSV", "");
            this->_endBool = true;
            return;
        }
    }
}

void    Bitcoin::verifInputDatas(std::map<int, std::string> _map){
    
    std::map<int, std::string>  _line;
    std::map<int, std::string>::iterator it;

    for (it = _map.begin(); it != _map.end(); it++) {

        this->_errorBool = false;
        this->_errorLoopInput = false;

        _line = this->splitAt(it->second, '|', false);

        if (this->_errorLoopInput == false && it->second.length() < 12)
            this->printError("error: bad input =>", this->splitAt(it->second, '|', false)[0]);

        if (this->_errorLoopInput == false) {
            _line = splitAt(it->second, '|', false);

            if ((this->_errorLoopInput == false) && (_line[0].empty() || _line[1].empty()))
                this->printError("error: bad input =>", this->splitAt(it->second, '|', false)[0]);

            if (this->_errorLoopInput == false && (_line[0].find_first_not_of(" \t") != std::string::npos && _line[1].find_first_not_of(" \t") != std::string::npos)) { 
                _line[0] = trim(_line[0]);
                _line[1] = trim(_line[1]);
            }

            if ((this->_errorLoopInput == false) && _line[0].empty())
                this->printError("error: bad input =>", this->splitAt(it->second, '|', false)[0]);

            if ((this->_errorLoopInput == false) && _line[1].empty())
                this->printError("error: bad input =>", this->splitAt(it->second, '|', false)[0]);

            float _value = atof(_line[1].c_str());

            if (_value < 1 && this->_errorLoopInput == false)
                this->printError("error: not a positive number", "");
            
            if (_value > 999 && this->_errorLoopInput == false)
                this->printError("error: too large a number", "");

            if (this->_errorLoopInput == false && (_line[0][4] != '-' || _line[0][7] != '-'))
                this->printError("error: bad input =>", this->splitAt(it->second, '|', false)[0]);

            std::map<int, std::string>  _date = splitAt(_line[0], '-', true);

            if ((this->_errorLoopInput == false) && (_date[0].length() != 4 || _date[1].length() != 2 || _date[2].length() != 2))
                this->printError("error: bad input =>", this->splitAt(it->second, '|', false)[0]);

            if ((this->_errorLoopInput == false) && (!verifDateDigit(_date[0]) || !verifDateDigit(_date[1]) || !verifDateDigit(_date[2]) || !verifDateDigit(_line[1])))
                this->printError("error: bad input =>", this->splitAt(it->second, '|', false)[0]);

            if ((this->_errorLoopInput == false) && !verifDateConformity(_date))
                this->printError("error bad input =>", trim(this->splitAt(it->second, '|', false)[0]));
        }

        if (this->_errorBool == false)
            this->calculate(trim(this->splitAt(it->second, '|', false)[0]), trim(this->splitAt(it->second, '|', false)[1]));
    }
}

static int stringToInt(const std::string& str) {
    int result = 0;
    int i = 0;
    
    for (str[i]; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
        else {
            return -1;
        }
    }
    return result;
}

bool Bitcoin::verifDateConformity(std::map<int, std::string> map) {
    
    int year = stringToInt(map[0]);
    int month = stringToInt(map[1]);
    int day = stringToInt(map[2]);

    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1) {
        return false;
    }

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return (day <= 29);
        }
        else {
            return (day <= 28);
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return (day <= 30);
    }
    else {
        return (day <= 31);
    }
}


bool Bitcoin::verifDateDigit(std::string str) {
    bool decimalPointFound = false;

    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            if (str[i] == '.' && !decimalPointFound)
                decimalPointFound = true;
            else
                return (false);
        }
    }
    return (true);
}

bool    Bitcoin::verifFiles(std::string _filename) {

    std::ifstream 	_file(_filename.c_str());

    if (_file.is_open() == false){
        this->printError("error: could not open file", "");
        _file.close();
        return (false);
    }
    _file.close();
    return (true);
}


void    Bitcoin::printError(std::string _errorMessage, std::string _arg) {
    std::cout << RED << _errorMessage << " " << _arg << RESET << std::endl;
    this->_errorBool = true;
    this->_errorLoopInput = true;
}

/*--------------------------Getters--------------------------*/
std::string    Bitcoin::getFilename(void) const{
    return (this->_filename);
}

/*--------------------------Setters--------------------------*/
void        Bitcoin::setFilename(std::string filename){
    this->_filename = filename;
}