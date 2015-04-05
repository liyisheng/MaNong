#include <iostream>
#include "parser.h"
#include "scanner.h"

int main()
{
    EStatus status = STATUS_OK;
    do
    {
        std::cout << "> ";
        std::string buf;
        getline(std::cin, buf);

        Scanner scanner(buf);
        Parser parser(scanner);
        parser.parse();
        double result = parser.calculate();
        std::cout << buf << " = " << result << std::endl;
        status = parser.getStatus();
    }while(status != STATUS_QUIT);

    return 0;
}
