#include <iostream>
#include <filesystem>
#include <string>

int main(int argc, char *argv[])
{
   bool flag;
   int directoryCount = 0;
   int fileCount = 0;
   long int sizeCount = 0;
   std::string entry = argv[1];

   // validate directory path
   std::filesystem::directory_entry d(entry);
   flag = d.is_directory();

   if (argc == 2 && flag == true)
   {
      // recursively traverses the given directory
      // skip over unaccessible entries
      for (auto& p : std::filesystem::recursive_directory_iterator(entry, std::filesystem::directory_options::skip_permission_denied))
      {
         try
         {
            std::filesystem::directory_entry d2(p.path());

            // entry is a link 
            if (d2.is_symlink() == true)
            {
               continue;
            }
            // entry is a directory
            if (d2.is_directory() == true)
            {
               directoryCount++;
            }
            // entry is a plain file
            else
            {
               fileCount++;
               sizeCount = sizeCount + std::filesystem::file_size(p.path());
            }
         }

         catch (std::filesystem::filesystem_error e)
         {
            continue;
         }
      }
      // display results
      std::cout << "The total number of directories in directory " +  entry + " is:  ";
      std::cout << directoryCount << std::endl;

      std::cout << "The total number of files in directory " + entry + " is:  ";
      std::cout << fileCount << std::endl;

      std::cout << "The total number of bytes occupied by all files in directory " + entry + " is:  ";
      std::cout << sizeCount << std::endl;
   }

   return 0;
}

