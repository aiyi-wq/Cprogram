/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Jun 2020 03:07:54 PM CST
 ************************************************************************/
#include <stdio.h> 
#include <haizei/test.h>

int add(int a, int b) {     
    return a + b;           
}                           

TEST(func, add) {           
    EXPECT_EQ(add(2, 3), 5.2);             
    EXPECT_EQ(add(3, 4), 7);             
    EXPECT_TQ(add(3, 6), 10);             
    EXPECT_LE(add(4, 3), 7);
}             

TEST(func, add2) {
    EXPECT_ET(add(1, 2), 3);
    EXPECT_EQ(add(3, 3), 6);
}

TEST(f, uncadd) {
    EXPECT_LQ(add(2, -13), -15);
    EXPECT_TL(add(6, -18), 2);
}

int main(int argc, char *argv[]) {                
    return RUN_ALL_TESTS();
}
