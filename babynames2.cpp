#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
   Reads name information, prints the name if total >= 0, and adjusts the total.
   @param in_file the input stream
   @param total the total percentage that should still be processed
*/
void process_name(ifstream& in_file, string gender, double& total)
{
   string name;
   int count;
   double percent;
   string temp;
   
   in_file >> name >> count >> temp >> percent;
   

   if (in_file.fail()) {   // Check for failure after each input
      cout << "did i fail 1?";
      return; 
   } 
   if (total > 0 && gender == "Boy ") {    
      cout << gender << "Name: " << name << " | ";
   } else if(total > 0 && gender == "Girl ") {    
      cout << gender << "Name: " << name;
   }

   total = total - percent;

}

int main()
{  
   ifstream in_file;
   in_file.open("babynames_with_percentages_final2.txt"); 

   if (in_file.fail()) { return 0; } // Check for failure after opening

   double boy_total = 50;
   double girl_total = 50;

   string gender;
   int rank;

   while (boy_total > 0 || girl_total > 0)
   {
   
      in_file >> rank;
      
      if (in_file.fail()) { 
         cout << "Something failed." << rank;

         return 0; 
      } 

      cout << "Rank " << rank << " - ";
      process_name(in_file, gender = "Boy ", boy_total);
      process_name(in_file, gender = "Girl ", girl_total);

      cout << endl;
   }

   return 0;
}