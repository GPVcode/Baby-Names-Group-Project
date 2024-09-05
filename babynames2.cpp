#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
   Reads name information, prints the name if total >= 0, and adjusts the total.
   @param in_file the input stream
   @param total the total percentage that should still be processed
*/
void process_name(ifstream& in_file, int& rank, double& total)
{
   string name;
   int count;
   double percent;
   string temp;
   in_file >> name >> count >> temp >> percent;

   cout << name << " " << count << " " << percent << endl;
   
   if (in_file.fail()) { return; } // Check for failure after each input
   // if (total > 0) { cout << name << " "; }
   total = total - percent;
   cout << "total: " << total;
}

int main()
{  
   ifstream in_file;
   // if (in_file.fail()) { return 0; } // Check for failure after opening

   double boy_total = 50;
   double girl_total = 50;

   while (boy_total > 0 || girl_total > 0)
   {
      in_file.open("babynames_with_percentages_final2.txt"); 
      // string sLine;
      // getline(in_file, sLine);
      // cout << sLine.data();

      int rank;
      in_file >> rank;
      if (in_file.fail()) { return 0; } 
      
      cout << rank << " ";
  
      process_name(in_file, rank, boy_total);
      // process_name(in_file, girl_total);

      cout << endl;
   }

   return 0;
}