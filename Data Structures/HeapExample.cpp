#include <iomanip>
#include <iostream>
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef std::vector<int> vector_int;

template <typename T>
void process(T A, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		A[i] = size - i;
	}
}
int heap_code()
{
  int* buff = new int[32];
	process(buff, 32);
	std::vector<int> v(buff, buff + 31);
	auto gap = v.size();
	cout << endl << "The tree is : " << endl << endl;
	for (auto i = 0; i < v.size(); i++)
	{
		for (auto j = 0; j <= gap; j++)
		{
			cout << " ";
		}
		cout << v[i];
		for (auto j = 0; j <= gap-1; j++)
		{
			cout << " ";
		}
		if ((i == 0) || (i == 2) || (i == 6) || (i == 14) || (i == 30) || (i == 62))
		{
			cout << endl;
			gap = gap / 2;
			cout << endl;
		}
	}
	for (const auto& elem : v)
	{
		std::make_heap(v.begin(), v.end());
		std::pop_heap(v.begin(), v.end());
		v.pop_back();
		gap = v.size();
		cout << endl << endl << "Extracting Max Element : " << v.front() <<  endl << endl;
		for (auto i = 0; i < v.size(); i++)
		{
			for (auto j = 0; j <= gap; j++)
			{
				cout << " ";
			}
			cout << v[i];
			for (auto j = 0; j <= gap - 1; j++)
			{
				cout << " ";
			}
			if ((i == 0) || (i == 2) || (i == 6) || (i == 14) || (i == 30) || (i == 62))
			{
				cout << endl;
				gap = gap / 2;
				cout << endl;
			}
		}
	}
    delete[] buff;
    return 0;
}

/*
Output is : 
The tree is : 

                                32                               

                31                               30               

        29               28               27               26       

    25       24       23       22       21       20       19       18   

  17   16   15   14   13   12   11   10   9   8   7   6   5   4   3   2 



Extracting Max Element : 31

                               31                              

                29                               30               

        25               28               27               26       

    17       24       23       22       21       20       19       18   

  2   16   15   14   13   12   11   10   9   8   7   6   5   4   3 

Extracting Max Element : 30

                              30                             

               29                             27              

        25               28               21               26       

    17       24       23       22       9       20       19       18   

  2   16   15   14   13   12   11   10   3   8   7   6   5   4 

Extracting Max Element : 29

                             29                            

               28                             27              

        25               23               21               26       

    17       24       13       22       9       20       19       18   

  2   16   15   14   4   12   11   10   3   8   7   6   5 

Extracting Max Element : 28

                            28                           

              25                           27             

       24             23             21             26      

    17       15       13       22       9       20       19       18   

  2   16   5   14   4   12   11   10   3   8   7   6 

Extracting Max Element : 27

                           27                          

              25                           26             

       24             23             21             19      

    17       15       13       22       9       20       6       18   

  2   16   5   14   4   12   11   10   3   8   7 

Extracting Max Element : 26

                          26                         

             25                         21            

       24             23             20             19      

    17       15       13       22       9       7       6       18   

  2   16   5   14   4   12   11   10   3   8 

Extracting Max Element : 25

                         25                        

             24                         21            

       17             23             20             19      

    16       15       13       22       9       7       6       18   

  2   8   5   14   4   12   11   10   3 

Extracting Max Element : 24

                        24                       

            23                       21           

      17           22           20           19     

   16     15     13     11     9     7     6     18  

  2   8   5   14   4   12   3   10 

Extracting Max Element : 23

                       23                      

            22                       21           

      17           13           20           19     

   16     15     12     11     9     7     6     18  

  2   8   5   14   4   10   3 

Extracting Max Element : 22

                      22                     

           17                     21          

      16           13           20           19     

   8     15     12     11     9     7     6     18  

  2   3   5   14   4   10 

Extracting Max Element : 21

                     21                    

           17                     20          

      16           13           10           19     

   8     15     12     11     9     7     6     18  

  2   3   5   14   4 

Extracting Max Element : 20

                    20                   

          17                   19         

     16         13         10         18    

   8     15     12     11     9     7     6     4  

  2   3   5   14 

Extracting Max Element : 19

                   19                  

          17                   18         

     16         13         10         14    

   8     15     12     11     9     7     6     4  

  2   3   5 

Extracting Max Element : 18

                  18                 

         17                 14        

     16         13         10         6    

   8     15     12     11     9     7     5     4  

  2   3 

Extracting Max Element : 17

                 17                

         16                 14        

     15         13         10         6    

   8     3     12     11     9     7     5     4  

  2 

Extracting Max Element : 16

                16               

        15               14       

    8       13       10       6   

  2   3   12   11   9   7   5   4 



Extracting Max Element : 15

               15              

        13               14       

    8       12       10       6   

  2   3   4   11   9   7   5 

Extracting Max Element : 14

              14             

       13             10      

    8       12       9       6   

  2   3   4   11   5   7 

Extracting Max Element : 13

             13            

       12             10      

    8       11       9       6   

  2   3   4   7   5 

Extracting Max Element : 12

            12           

      11           10     

   8     7     9     6  

  2   3   4   5 

Extracting Max Element : 11

           11          

      8           10     

   5     7     9     6  

  2   3   4 

Extracting Max Element : 10

          10         

     8         9    

   5     7     4     6  

  2   3 

Extracting Max Element : 9

         9        

     8         6    

   5     7     4     3  

  2 

Extracting Max Element : 8

        8       

    7       6   

  5   2   4   3 



Extracting Max Element : 7

       7      

    5       6   

  3   2   4 

Extracting Max Element : 6

      6     

   5     4  

  3   2 

Extracting Max Element : 5

     5    

   3     4  

  2 

Extracting Max Element : 4

    4   

  3   2 



Extracting Max Element : 3

   3  

  2 

Extracting Max Element : 2

  2 



Extracting Max Element : 2

*/