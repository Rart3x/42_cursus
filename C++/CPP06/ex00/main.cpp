#include "ScalarConverter.hpp"

static void verif_args(int ac){
    
    if (ac != 2)
        throw ScalarConverter::InvalidNbArgs();
}

static void exceptions(void){
   
    try{
        throw;
    }
    catch (ScalarConverter::CharException &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::CharExceptionUndisplayable &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::DoubleException &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::FloatException &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::FloatInfFException &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::FloatLessInfFException &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::FloatNanFException &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::IntException &e){
        std::cout << e.what() << std::endl;
    }
    catch (ScalarConverter::InvalidNbArgs &e){
        std::cout << e.what() << std::endl;
    }

}

int main(int ac, char **av){

    try
    {
        ScalarConverter conv;

        verif_args(ac);
        conv.convert(av[1]);
    }
    catch(...)
    {
        exceptions();
    }
    return (0);
}
