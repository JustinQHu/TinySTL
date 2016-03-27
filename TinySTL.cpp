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
 

	 for (tiny::vector<int>::iterator i = iv.begin(); i != iv.end(); ++i)
	 {

		 std::cout << "iterator dereference : " << *i << std::endl;
	

	 }

 


	std::cout << iv.front() << "\t" << iv.back() << std::endl;
	std::cout << iv.at(0) << "\n"
		<< iv.at(1) << "\n"
		<< iv.at(2) << "\n"
		<< iv.at(3) << "\n"
		<< iv.at(4) << "\n" << std::endl;
	iv.resize(3);
	std::cout << "size: " << iv.size() << " capacity:   " << iv.capacity() << std::endl;
	std::cout << iv.at(0) << "\n"
		<< iv.at(1) << "\n"
		<< iv.at(2) << "\n" << std::endl;
	iv.resize(8);
	std::cout << "size: " << iv.size() << " capacity:   " << iv.capacity() << std::endl;
	std::cout << iv.at(0) << "\n"
		<< iv.at(1) << "\n"
		<< iv.at(2) << "\n"
		<< iv.at(3) << "\n" 
		<< iv.at(4) << "\n" 
		<< iv.at(5) << "\n" 
		<< iv.at(6) << "\n" 
		<< iv.at(7) << "\n" << std::endl;

	std::cout<<iv[0]<<"\n"
		<< iv[1] << "\n"
		<< iv[2] << "\n"
		<< iv[3] << "\n"
		<< iv[4] << "\n"
		<< iv[5] << "\n"
		<< iv[6] << "\n"
		<< iv[7] << "\n"<<std::endl;






    return 0;
}

