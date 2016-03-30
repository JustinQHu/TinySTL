// TinySTL.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<string>

#include"vector.h"



class testType
{
	int i;
	std::string s;
	double d;

};


//test code
int main()
{
	//test pop_back()
	tiny::vector<int>  iv;
	std::cout << "max_size: " << iv.max_size() << std::endl;
	tiny::vector<char> cv;
	std::cout << "max_size: " << cv.max_size() << std::endl;


	for (int i = 0; i < 5; ++i)
	{
		iv.push_back(i);
		std::cout << "size: " << iv.size() <<" capacity:   "<<iv.capacity()<< std::endl;
	}



	tiny::vector<int>::iterator i;
	i = iv.begin();
	iv.end();
	std::cout<<"dereference: "<<*(i+1)<<std::endl;
	std::cout << "is equal: " << ( i == iv.begin()) << std::endl;

     for (tiny::vector<int>::iterator i = iv.begin(); i != iv.end(); ++i)
	{
		
		std::cout <<"iterator dereference : "<< *i << std::endl;
		*i = *i + 5;

	}
 
	 std::cout << "****************************************" << std::endl;
	 for (tiny::vector<int>::iterator i = iv.begin(); i != iv.end(); ++i)
	 {

		 std::cout << "iterator dereference : " << *i << std::endl;
	

	 }

	 iv.pop_back();
	 std::cout << "****************************************" << std::endl;
	 for (tiny::vector<int>::iterator i = iv.begin(); i != iv.end(); ++i)
	 {

		 std::cout << "iterator dereference : " << *i << std::endl;


	 }


	 iv.erase(iv.begin());

	 std::cout << "****************************************" << std::endl;
	 for (tiny::vector<int>::iterator i = iv.begin(); i != iv.end(); ++i)
	 {

		 std::cout << "iterator dereference : " << *i << std::endl;


	 }
	 iv.erase(iv.end() - 1);
	 std::cout << "****************************************" << std::endl;
	 for (tiny::vector<int>::iterator i = iv.begin(); i != iv.end(); ++i)
	 {

		 std::cout << "iterator dereference : " << *i << std::endl;


	 }

	 iv.push_back(10);
	 iv.push_back(10);
	 iv.push_back(10);

	 std::cout << "****************************************" << std::endl;
	 for (tiny::vector<int>::iterator i = iv.begin(); i != iv.end(); ++i)
	 {

		 std::cout << "iterator dereference : " << *i << std::endl;


	 }



	 tiny::vector<int> iv2(10,8);
	 std::cout << "****************************************" << std::endl;
	 for (tiny::vector<int>::iterator i = iv2.begin(); i != iv2.end(); ++i)
	 {

		 std::cout << "iterator dereference : " << *i << std::endl;


	 }

	 int k = 5;


	 tiny::vector<int> iv3(2, k);
	 std::cout << "****************************************" << std::endl;
	 for (tiny::vector<int>::iterator i = iv3.begin(); i != iv3.end(); ++i)
	 {

		 std::cout << "iterator dereference : " << *i << std::endl;


	 }


	 iv3.insert(iv3.end(), 6);

	 std::cout << "****************************************" << std::endl;
	 for (tiny::vector<int>::iterator i = iv3.begin(); i != iv3.end(); ++i)
	 {

		 std::cout << "iterator dereference : " << *i << std::endl;


	 }



    return 0;
}

