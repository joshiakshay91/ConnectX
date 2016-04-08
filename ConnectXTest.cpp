/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"

class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};
//is placePiece working
TEST(ConnectXTest, SettingValue)
{
ConnectX Game;
Game.placePiece(0);
bool flag;
int i=Game.at(0,5);
if(i==2 ||i==1)//checking wether B or W is present
  {
    flag=true;
  }
else
  {
		flag=false;
  }
	ASSERT_TRUE(flag);//if flag is true piece was placed properly
}

//Placing something to a invalid location
TEST(ConnectXTest, settingWrongVal)
{
ConnectX Game;
Game.placePiece(1000);
bool flag=true;
for(int w=0;w<7;w++)
{
  for(int h=0;h<6;h++)
  {
    int i=Game.at(w,h);
    if(i==2 ||i==1)// if B/W
      {
        flag=false;
        break;
      }
  }
  if(!flag) break;
}
ASSERT_TRUE(flag);//it should silently ignore and have nothing on board
}

//Testing boundry
TEST(ConnectXTest, InvalidHeightnWidth)
{
ConnectX Game;
Game.placePiece(1);
bool flag=true;
int val=Game.at(-99,-100);//giving invalid height & width
if(val!=-1) flag=false;//it should return -1
ASSERT_TRUE(flag);
}//this test works

//Testing positively invalid values
TEST(ConnectXTest, InvalidHeightnWidth2)
{
ConnectX Game;
Game.placePiece(1);
bool flag=true;
int val=Game.at(6000,900);//giving invalid height & width
if(val!=-1) flag=false;//it should return -1
ASSERT_TRUE(flag);
}//this test works

// This one has tracked buggy code
TEST(ConnectXTest, InvalidWidth)
{
ConnectX Game;
Game.placePiece(1);
bool flag=true;
int val=Game.at(700,5);//giving invalid Width
if(val!=-1) flag=false;//it should return -1 from at for invalid location
ASSERT_TRUE(flag);
}//but observed that it is not returning -1

// This one has tracked buggy code
TEST(ConnectXTest, InvalidWidth2)
{
ConnectX Game;
Game.placePiece(1);
bool flag=true;
int val=Game.at(-1,5);//giving invalid Width
if(val!=-1) flag=false;//it should return -1 from at for invalid location
ASSERT_TRUE(flag);
}//but observed that it is not returning -1


//Similar to above test
TEST(ConnectXTest, InvalidHeight)
{
ConnectX Game;
Game.placePiece(1);
bool flag=true;
int val=Game.at(0,700);//giving invalid height
if(val!=-1) flag=false;//it should return -1
ASSERT_TRUE(flag);
}//this test works


//Similar to above test
TEST(ConnectXTest, InvalidHeight2)
{
ConnectX Game;
Game.placePiece(1);
bool flag=true;
int val=Game.at(0,-1);//giving invalid height
if(val!=-1) flag=false;//it should return -1
ASSERT_TRUE(flag);
}//this test works

//is change turn working
TEST(ConnectXTest, TurnTurn)
{
ConnectX Game;
bool flag=true;
int Turn=Game.whoseTurn();
if(Turn==1)//if it was white's turn
{
  Game.placePiece(1);//after placing
  int secTurn=Game.whoseTurn();//is turn changing
  if(secTurn==1)  flag=false;// if not flag is false
}
else if(Turn==2)//if it was black's turn
{
  Game.placePiece(1);//after placing is turn changing
  int secTurn=Game.whoseTurn();
  if(secTurn==2)  flag=false;//if not falg is false
}
ASSERT_TRUE(flag);//check flag
}


//passing new parameters to constructor and seeing that
//it constructs a new board for game
TEST(ConnectXTest, ParameterziedConst)
{
	ConnectX Game(8,8,5);
	Game.placePiece(7);
	bool flag=true;
	int i=Game.at(7,7);
	if(i==2 ||i==1)//checking wether B or W is present
	  {
	    flag=true;
	  }
	else
	  {
			flag=false;
	  }
		ASSERT_TRUE(flag);//if flag is true piece was placed properly
}
