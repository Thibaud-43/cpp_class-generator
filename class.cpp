#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Class
{
    private:
        Class();
        std::string     m_className;
        std::string     m_hppFile;
        std::string     m_cppFile;
        std::ofstream   m_myFileWriting;
    public:
        Class(std::string name);
        ~Class();
        void        createCpp(void);
        void        createHpp(void);
};

Class::Class(void)
{
}

Class::Class(std::string name): m_hppFile(name + ".hpp"), m_cppFile(name + ".cpp"), m_className(name)
{

}

Class::~Class()
{
}

void        Class::createCpp(void)
{
    m_myFileWriting.open(m_cppFile);
    if (m_myFileWriting.is_open())
    {    
        m_myFileWriting << "#include \"" << m_className <<".hpp\"" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "" << m_className <<"::" << m_className <<"()" << std::endl;
        m_myFileWriting << "{" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "}" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "" << m_className <<"::" << m_className <<"(" << m_className <<" const & src)" << std::endl;
        m_myFileWriting << "{" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "}" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "" << m_className <<"::~" << m_className <<"()" << std::endl;
        m_myFileWriting << "{" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "}" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "" << m_className <<"\t&\t" << m_className <<"::operator=(" << m_className <<" const & rhs)" << std::endl;
        m_myFileWriting << "{" << std::endl;
        m_myFileWriting << "\tif (&rhs == this)" << std::endl;
        m_myFileWriting << "\t\treturn *this;" << std::endl;
        m_myFileWriting << "\treturn *this;" << std::endl;
        m_myFileWriting << "}" << std::endl;
        m_myFileWriting.close();
    }
    else
        std::cout << "Error with file" << std::endl;
}

void        Class::createHpp(void)
{
    m_myFileWriting.open(m_hppFile);
    if (m_myFileWriting.is_open())
    {    
        m_myFileWriting << "#ifndef "<< m_className <<"_HPP" << std::endl;
        m_myFileWriting << "# define "<< m_className <<"_HPP" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "#include <iostream>" << std::endl;
        m_myFileWriting << "#include <string>" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "class "<< m_className <<"" << std::endl;
        m_myFileWriting << "{" << std::endl;
        m_myFileWriting << "\tprivate:" << std::endl;
        m_myFileWriting << "\tpublic:" << std::endl;
        m_myFileWriting << "\t\t"<< m_className <<"();" << std::endl;
        m_myFileWriting << "\t\t"<< m_className <<"("<< m_className <<" const & src);" << std::endl;
        m_myFileWriting << "\t\tvirtual ~"<< m_className <<"();" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "\t\t"<< m_className <<"\t&\toperator=("<< m_className <<" const & rhs);" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "};" << std::endl;
        m_myFileWriting << "" << std::endl;
        m_myFileWriting << "#endif" << std::endl;
        m_myFileWriting.close();
    }
    else
        std::cout << "Error with file" << std::endl;
}

int main(int argc, char const *argv[])
{
    if(argc == 1)
    {
        std::cout << "To create a class use the command : class <className1> <className2> <...>" << std::endl;
        return 0;
    }
    for(int i = 1; i < argc; i++)
    {
        Class test(argv[i]);
        test.createHpp();
        test.createCpp();
    }
    return 0;
}
