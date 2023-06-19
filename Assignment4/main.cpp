/** 
  * Assignment 4 for COSE213 Data Structures
  *
  * Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  * 2022. 5. 22
  *
  */
  
#include "LinkedBinaryTree.h"
#include "SearchTree.h" 
#include "AVLTree.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

#include <iostream>
 
using namespace std;

int main()
{
	typedef Entry<int, float> EntryType;

	LinkedBinaryTree<EntryType> t;
	
	std::cout << "Size : " << t.size() << std::endl;
	
	t.addRoot();
	
	std::cout << "Size : " << t.size() << std::endl;
	
	
	//
	//
	//
	SearchTree<EntryType>	st;
	
	std::cout << "Size : " << st.size() << std::endl;
	st.insert(1, 2.5);
	st.insert(3, 4.5);
	st.insert(7, 5.5);
	st.insert(2, 1.5);
	st.insert(3, 8.5);
	std::cout << "Size : " << st.size() << std::endl;

	for(SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
	{
			std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}
		
	st.erase(3);
	std::cout << "Size : " << st.size() << std::endl;
	for(SearchTree<EntryType>::Iterator it = st.begin(); it != st.end(); ++it)
	{
			std::cout << (*it).key() << " , " << (*it).value() << std::endl;
	}	
	
	std::cout << "------------" << std::endl;
	
	//
	//
	//
	AVLTree<EntryType>	avl;

	std::cout << "My Test for Assign_4" << std::endl;
	std::cout << "------------" << std::endl;
	
	// random test
	int nElem_a = 1000;
	int nElem_b = 10000;
	int nElem_c = 100000;
	int nElem_d = 1000000;
	// int nElem = 100000; //100000000;
	
	int *key_a = new int[nElem_a];
	float *val_a = new float[nElem_a];
	int *key_b = new int[nElem_b];
	float *val_b = new float[nElem_b];
	int *key_c = new int[nElem_c];
	float *val_c = new float[nElem_c];
	int *key_d = new int[nElem_d];
	float *val_d = new float[nElem_d];
	
	// std::srand(std::time(0)); // use current time as seed for random generator
   
	SearchTree<EntryType>	st_a;
	SearchTree<EntryType>	st_b;
	SearchTree<EntryType>	st_c;
	SearchTree<EntryType>	st_d;

	AVLTree<EntryType>	avl_a;
	AVLTree<EntryType>	avl_b;
	AVLTree<EntryType>	avl_c;
	AVLTree<EntryType>	avl_d;

	clock_t tm;	

	// initialize for Skewed case
	
	for (int i=0; i<nElem_a; i++)
	{
		key_a[i] = i;
		val_a[i] = i;
	}
	for (int i=0; i<nElem_b; i++)
	{
		key_b[i] = i;
		val_b[i] = i;
	}
	for (int i=0; i<nElem_c; i++)
	{
		key_c[i] = i;
		val_c[i] = i;
	}
	for (int i=0; i<nElem_d; i++)
	{
		key_d[i] = i;
		val_d[i] = i;
	}

  //
  // Insert_Skewed test for SearchTree
  //

	std::cout << "Case a = 1000" << std::endl;
	std::cout << "Case b = 10000" << std::endl;
	std::cout << "Case c = 100000" << std::endl;
	std::cout << "Case d = 1000000" << std::endl;
	std::cout << "------------" << std::endl;

	std::cout << "Skewed Case Test" << std::endl;
	std::cout << "------------" << std::endl;
    
    tm = clock();
	for (int i = 0; i < nElem_a; i++)
	{
		st_a.insert(key_a[i], val_a[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Insertion-a_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_b; i++)
	{
		st_b.insert(key_b[i], val_b[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Insertion-b_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_c; i++)
	{
		st_c.insert(key_c[i], val_c[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Insertion-c_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_d; i++)
	{
		st_d.insert(key_d[i], val_d[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Insertion-d_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	std::cout << "------------" << std::endl;

  //
  // Find_Skewed test for SearchTree
  //

	tm = clock();
	for (int i = 0; i < nElem_a; i++)
	{
		st_a.find(key_a[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Find-a_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_b; i++)
	{
		st_b.find(key_b[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Find-b_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_c; i++)
	{
		st_c.find(key_c[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Find-c_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_d; i++)
	{
		st_d.find(key_d[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Find-d_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	std::cout << "------------" << std::endl;

  // erase data

	for (int i=0; i<nElem_a; i++)
	{
		st_a.erase(key_a[i]);
	}

	for (int i=0; i<nElem_b; i++)
	{
		st_b.erase(key_b[i]);
	}

	for (int i=0; i<nElem_c; i++)
	{
		st_c.erase(key_c[i]);
	}

	for (int i=0; i<nElem_d; i++)
	{
		st_d.erase(key_d[i]);
	}

  //
  // Insert_Skewed test for AVL
  //
    
    tm = clock();
	for (int i = 0; i < nElem_a; i++)
	{
		avl_a.insert(key_a[i], val_a[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Insertion-a_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_b; i++)
	{
		avl_b.insert(key_b[i], val_b[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Insertion-b_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_c; i++)
	{
		avl_c.insert(key_c[i], val_c[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Insertion-c_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_d; i++)
	{
		avl_d.insert(key_d[i], val_d[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Insertion-d_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	std::cout << "------------" << std::endl;

  //
  // Find_Skewed test for AVL
  //

	tm = clock();
	for (int i = 0; i < nElem_a; i++)
	{
		avl_a.find(key_a[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Find-a_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_b; i++)
	{
		avl_b.find(key_b[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Find-b_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_c; i++)
	{
		avl_c.find(key_c[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Find-c_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_d; i++)
	{
		avl_d.find(key_d[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Find-d_Skewed.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	std::cout << "------------" << std::endl;

	// erase data

	for (int i=0; i<nElem_a; i++)
	{
		avl_a.erase(key_a[i]);
	}

	for (int i=0; i<nElem_b; i++)
	{
		avl_b.erase(key_b[i]);
	}

	for (int i=0; i<nElem_c; i++)
	{
		avl_c.erase(key_c[i]);
	}

	for (int i=0; i<nElem_d; i++)
	{
		avl_d.erase(key_d[i]);
	}

	// initialize for Random Case

	std::srand(std::time(0));
	
	for (int i=0; i<nElem_a; i++)
	{
		key_a[i] = std::rand();
		val_a[i] = (float) std::rand()/RAND_MAX * 20000;
	}
	for (int i=0; i<nElem_b; i++)
	{
		key_b[i] = std::rand();
		val_b[i] = (float) std::rand()/RAND_MAX * 20000;
	}
	for (int i=0; i<nElem_c; i++)
	{
		key_c[i] = std::rand();
		val_c[i] = (float) std::rand()/RAND_MAX * 20000;
	}
	for (int i=0; i<nElem_d; i++)
	{
		key_d[i] = std::rand();
		val_d[i] = (float) std::rand()/RAND_MAX * 20000;
	}

  //
  // Insert_Random test for SearchTree
  //

	std::cout << "Random Case Test" << std::endl;
	std::cout << "------------" << std::endl;
    
    tm = clock();
	for (int i = 0; i < nElem_a; i++)
	{
		st_a.insert(key_a[i], val_a[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Insertion-a_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_b; i++)
	{
		st_b.insert(key_b[i], val_b[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Insertion-b_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_c; i++)
	{
		st_c.insert(key_c[i], val_c[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Insertion-c_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_d; i++)
	{
		st_d.insert(key_d[i], val_d[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Insertion-d_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	std::cout << "------------" << std::endl;

  //
  // Find_Random test for SearchTree
  //

	tm = clock();
	for (int i = 0; i < nElem_a; i++)
	{
		st_a.find(key_a[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Find-a_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_b; i++)
	{
		st_b.find(key_b[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Find-b_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_c; i++)
	{
		st_c.find(key_c[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Find-c_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_d; i++)
	{
		st_d.find(key_d[i]);
	}
	tm = clock() - tm;
	printf ("ST took %f seconds for Find-d_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	std::cout << "------------" << std::endl;

  //
  // Insert_Random test for AVL
  //
    
    tm = clock();
	for (int i = 0; i < nElem_a; i++)
	{
		avl_a.insert(key_a[i], val_a[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Insertion-a_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_b; i++)
	{
		avl_b.insert(key_b[i], val_b[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Insertion-b_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_c; i++)
	{
		avl_c.insert(key_c[i], val_c[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Insertion-c_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_d; i++)
	{
		avl_d.insert(key_d[i], val_d[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Insertion-d_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	std::cout << "------------" << std::endl;

  //
  // Find_Random test for AVL
  //

	tm = clock();
	for (int i = 0; i < nElem_a; i++)
	{
		avl_a.find(key_a[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Find-a_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_b; i++)
	{
		avl_b.find(key_b[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Find-b_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_c; i++)
	{
		avl_c.find(key_c[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Find-c_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	tm = clock();
	for (int i = 0; i < nElem_d; i++)
	{
		avl_d.find(key_d[i]);
	}
	tm = clock() - tm;
	printf ("AVL took %f seconds for Find-d_Random.\n", ((float)tm)/(float)CLOCKS_PER_SEC);

	std::cout << "------------" << std::endl;
	
	return 0;
}