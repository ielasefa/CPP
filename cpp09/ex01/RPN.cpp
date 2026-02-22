bool    isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void    checkInput(std::string &input)
{
    if (input.empty())
    {
        std::cerr << "Error: input is empty" << std::endl;
        exit(1);
    }

    for (size_t i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]) && !isspace(input[i]) && !isOperator(input[i]))
        {
            std::cerr << "Error: invalid character in input: '" << input[i] << "'" << std::endl;
            exit(1);
        }
    }
}