#include <../cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h>
#include "../AVLTreeLib/AVLTreeLib.h"

namespace   {

    TEST(AVLTreeUnitTest, leftRootRotationAfterInsert)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 10);
        tree.insert(20, 20);
        std::string expected = "[10,10],[20,20],";
        ASSERT_EQ(expected, tree.toString());
        tree.insert(30, 30);
        expected = "[10,10],[20,20],[30,30],";
        ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, leftRotationAfterInsert)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(60, 60);
        tree.insert(20, 20);
        tree.insert(70, 70);
        tree.insert(10, 10);
        tree.insert(30, 30);
        tree.insert(80, 80);
        tree.insert(25, 25);
        tree.insert(40, 40);
        std::string expected = "[10,10],[20,20],[25,25],[30,30],[40,40],[60,60],[70,70],[80,80],";
        ASSERT_EQ(expected, tree.toString());
        tree.insert(50, 50);
        expected = "[10,10],[20,20],[25,25],[30,30],[40,40],[50,50],[60,60],[70,70],[80,80],";
        ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, rightLeftRootRotationAfterInsert)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 10);
        tree.insert(30, 30);
        std::string expected = "[10,10],[30,30],";
       ASSERT_EQ(expected, tree.toString());
        tree.insert(20, 20);
        expected = "[10,10],[20,20],[30,30],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, rightLeftRotationAfterInsert)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(60, 60);
        tree.insert(20, 20);
        tree.insert(70, 70);
        tree.insert(10, 10);
        tree.insert(30, 30);
        tree.insert(80, 80);
        tree.insert(25, 25);
        tree.insert(40, 40);
        std::string expected = "[10,10],[20,20],[25,25],[30,30],[40,40],[60,60],[70,70],[80,80],";
       ASSERT_EQ(expected, tree.toString());
        tree.insert(22, 22);
        expected = "[10,10],[20,20],[22,22],[25,25],[30,30],[40,40],[60,60],[70,70],[80,80],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, rightRootRotationAfterInsert)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(30, 30);
        tree.insert(20, 20);
        std::string expected = "[20,20],[30,30],";
       ASSERT_EQ(expected, tree.toString());
        tree.insert(10, 10);
        expected = "[10,10],[20,20],[30,30],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, rightRotationAfterInsert)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(30, 30);
        tree.insert(20, 20);
        tree.insert(80, 80);
        tree.insert(10, 10);
        tree.insert(60, 60);
        tree.insert(90, 90);
        tree.insert(50, 50);
        tree.insert(70, 70);
        std::string expected = "[10,10],[20,20],[30,30],[50,50],[60,60],[70,70],[80,80],[90,90],";
       ASSERT_EQ(expected, tree.toString());
        tree.insert(40, 40);
        expected = "[10,10],[20,20],[30,30],[40,40],[50,50],[60,60],[70,70],[80,80],[90,90],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, leftRightRootRotationAfterInsert)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(30, 30);
        tree.insert(10, 10);
        std::string expected = "[10,10],[30,30],";
       ASSERT_EQ(expected, tree.toString());
        tree.insert(20, 20);
        expected = "[10,10],[20,20],[30,30],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, leftRightRotationAfterInsert)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(30, 30);
        tree.insert(20, 20);
        tree.insert(80, 80);
        tree.insert(10, 10);
        tree.insert(50, 50);
        tree.insert(90, 90);
        tree.insert(40, 40);
        tree.insert(60, 60);
        std::string expected = "[10,10],[20,20],[30,30],[40,40],[50,50],[60,60],[80,80],[90,90],";
       ASSERT_EQ(expected, tree.toString());
        tree.insert(70, 70);
        expected = "[10,10],[20,20],[30,30],[40,40],[50,50],[60,60],[70,70],[80,80],[90,90],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, ConstructEmpty)
    {
        AVLTreeLib<int, int> tree;
        std::string expected = "";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertToEmpty)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        std::string expected = "[10,100],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe2LevelOnTheLeftThereIsNoRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(5, 50);
        std::string expected = "[5,50],[10,100],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe2LevelOnTheRightThereIsNoLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(20, 200);
        std::string expected = "[10,100],[20,200],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe2LevelOnTheLeftThereIsRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(20, 200);
        tree.insert(5, 50);
        std::string expected = "[5,50],[10,100],[20,200],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe2LevelOnTheRightThereIsLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(5, 50);
        tree.insert(20, 200);
        std::string expected = "[5,50],[10,100],[20,200],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe3LevelLeftLeftThereIsNoRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(10, 100);
        std::string expected = "[10,100],[20,200],[50,500],[80,800],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe3LevelLeftLeftThereIsRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(30, 300);
        tree.insert(10, 100);
        std::string expected = "[10,100],[20,200],[30,300],[50,500],[80,800],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe3LevelLeftRightThereIsNoLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(30, 300);
        std::string expected = "[20,200],[30,300],[50,500],[80,800],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe3LevelLeftRightThereIsLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(10, 100);
        tree.insert(30, 300);
        std::string expected = "[10,100],[20,200],[30,300],[50,500],[80,800],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe3LevelRightLeftThereIsNoRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(70, 700);
        std::string expected = "[20,200],[50,500],[70,700],[80,800],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe3LevelRightLeftThereIsRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(90, 900);
        tree.insert(70, 700);
        std::string expected = "[20,200],[50,500],[70,700],[80,800],[90,900],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe3LevelRightRightThereIsNoLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(90, 900);
        std::string expected = "[20,200],[50,500],[80,800],[90,900],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertOnThe3LevelRightRightThereIsLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(70, 700);
        tree.insert(90, 900);
        std::string expected = "[20,200],[50,500],[70,700],[80,800],[90,900],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, insertExisting)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(70, 700);
        tree.insert(90, 900);
        std::cout << tree.print2D() << std::endl;
        tree.insert(50, 501);
        tree.insert(20, 201);
        tree.insert(80, 801);
        tree.insert(70, 701);
        tree.insert(90, 901);
        std::cout << tree.print2D() << std::endl;
        std::string expected = "[20,201],[50,501],[70,701],[80,801],[90,901],";
       ASSERT_EQ(expected, tree.toString());
    }
    TEST(AVLTreeUnitTest, findInEmpty)
    {
        AVLTreeLib<int, int> tree;
        EXPECT_TRUE(nullptr == tree.find(10));
    }
    TEST(AVLTreeUnitTest, findNotExisted)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(5, 50);
        tree.insert(20, 200);
        EXPECT_TRUE(nullptr == tree.find(2));
        EXPECT_TRUE(nullptr == tree.find(7));
        EXPECT_TRUE(nullptr == tree.find(12));
        EXPECT_TRUE(nullptr == tree.find(24));
    }
    TEST(AVLTreeUnitTest, findOnThe1LevelNoChildren)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
       ASSERT_EQ(100, *tree.find(10));
        tree.insert(5, 50);
       ASSERT_EQ(100, *tree.find(10));
        tree.insert(20, 200);
       ASSERT_EQ(100, *tree.find(10));
    }
    TEST(AVLTreeUnitTest, findOnThe1LevelIsLeftChild)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(5, 50);
       ASSERT_EQ(100, *tree.find(10));
    }
    TEST(AVLTreeUnitTest, findOnThe1LevelIsRightChild)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(20, 200);
       ASSERT_EQ(100, *tree.find(10));
    }
    TEST(AVLTreeUnitTest, findOnThe1LevelAreChildren)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(5, 50);
        tree.insert(20, 200);
       ASSERT_EQ(100, *tree.find(10));
    }
    TEST(AVLTreeUnitTest, findOnThe2LevelOnTheLeftThereIsNoRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(5, 50);
       ASSERT_EQ(50, *tree.find(5));
    }
    TEST(AVLTreeUnitTest, findOnThe2LevelOnTheRightThereIsNoLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(20, 200);
       ASSERT_EQ(200, *tree.find(20));
    }
    TEST(AVLTreeUnitTest, findOnThe2LevelOnTheLeftThereIsRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(20, 200);
        tree.insert(5, 50);
       ASSERT_EQ(50, *tree.find(5));
    }
    TEST(AVLTreeUnitTest, findOnThe2LevelOnTheRightThereIsLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(10, 100);
        tree.insert(5, 50);
        tree.insert(20, 200);
       ASSERT_EQ(200, *tree.find(20));
    }
    TEST(AVLTreeUnitTest, findOnThe3LevelLeftLeftThereIsNoRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(10, 100);
       ASSERT_EQ(100, *tree.find(10));
    }
    TEST(AVLTreeUnitTest, findOnThe3LevelLeftLeftThereIsRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(30, 300);
        tree.insert(10, 100);
       ASSERT_EQ(100, *tree.find(10));
    }
    TEST(AVLTreeUnitTest, findOnThe3LevelLeftRightThereIsNoLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(30, 300);
       ASSERT_EQ(300, *tree.find(30));
    }
    TEST(AVLTreeUnitTest, findOnThe3LevelLeftRightThereIsLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(10, 100);
        tree.insert(30, 300);
       ASSERT_EQ(300, *tree.find(30));
    }
    TEST(AVLTreeUnitTest, findOnThe3LevelRightLeftThereIsNoRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(70, 700);
       ASSERT_EQ(700, *tree.find(70));
    }
    TEST(AVLTreeUnitTest, findOnThe3LevelRightLeftThereIsRight)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(90, 900);
        tree.insert(70, 700);
       ASSERT_EQ(700, *tree.find(70));
    }
    TEST(AVLTreeUnitTest, findOnThe3LevelRightRightThereIsNoLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(90, 900);
       ASSERT_EQ(900, *tree.find(90));
    }
    TEST(AVLTreeUnitTest, findOnThe3LevelRightRightThereIsLeft)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(50, 500);
        tree.insert(20, 200);
        tree.insert(80, 800);
        tree.insert(70, 700);
        tree.insert(90, 900);
       ASSERT_EQ(900, *tree.find(90));
    }
    TEST(AVLTreeUnitTest, print0)
    {
        AVLTreeLib<int, int> tree;
        std::string s = tree.print2D();
        std::string s1 = "";
       ASSERT_EQ(s1, s);
    }
    TEST(AVLTreeUnitTest, print1)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(1, 1);
        std::string s = tree.print2D();
        std::string s1 = "[1, 1]\n";
        ASSERT_EQ(s1, s);
    }
    TEST(AVLTreeUnitTest, print3) // error wynika z wywołania funkcji w avltreelib (przekierowanie couta do stringa)
    // mozna to rozwiązać poprzez static stringstream w avltreelib i zamiast couta ładować do stringstreama
    {
        AVLTreeLib<int, int> tree;
        tree.insert(2, 2);
        tree.insert(1, 1);
        tree.insert(3, 3);
        std::string s = tree.print2D();
        std::string s1 = "[2, 2]\n    L: [1, 1]\n    R: [3, 3]\n";
        ASSERT_EQ(s1, s);
    }

    TEST(AVLTreeUnitTest, print7)
    {
        AVLTreeLib<int, int> tree;
        tree.insert(4, 4);
        tree.insert(2, 2);
        tree.insert(1, 1);
        tree.insert(3, 3);
        tree.insert(6, 6);
        tree.insert(5, 5);
        tree.insert(7, 7);

        std::string s = tree.print2D();
        std::string s1 = "[4, 4]\n    L: [2, 2]\n        L: [1, 1]\n        R: [3, 3]\n    R: [6, 6]\n        L: [5, 5]\n        R: [7, 7]\n";
        ASSERT_EQ(s1, s);
    }
}