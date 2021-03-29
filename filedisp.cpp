#include <iostream>
#include <string>

int main(int argc, char** argv)
{
   std::string option = argv[1];
   std::string directory = " ",
               files = " ", 
               size = " ";

   // get output of previous command
   getline(std::cin, directory);
   getline(std::cin, files);
   getline(std::cin, size);

   // display line based on user option
   if (option == "-d")
   {
      std::cout << directory << std::endl;
   }
   else if (option == "-f")
   {
      std::cout << files << std::endl;
   }
   else if (option == "-b")
   {
      std::cout << size << std::endl;
   }

   return 0;
}