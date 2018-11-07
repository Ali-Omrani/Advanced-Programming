
#include "rsdl.h"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
const int UNIT = 50;
const int RUN_HEIGHT = 250;
const int JUMP_HEIGHT = 150;
const int JUMP_WIDTH = 390;
const int SHOOT_HEIGHT = 250;
const int SHOOT_WIDTH = 387;
const int POSSIBLE_PITS_IN_PAGE = 5;
const int SCORE_DIGIT_SIZE = 50;
const int DIGIT_TO_CHAR = 48;
const int NUM_OF_ELEMENET_TYPES = 3;
const int ROCKET_HEIGHT = 300;
const int GROUND_WIDTH = 100;
const int GROUND_HEIGHT=400;
const int COIN_POINT = 5;
const int COIN_WIDTH = 80;
const int COIN_HEIGHT = 80;
const int PIT_WIDTH = 30;
const int PIT_FRONT = 130;
const int PLAYER_HEIGHT = 165; 
const int PLAYER_WIDTH = 100;
const int PLAYER_POSE = 400;
const int CENTER = 450;
const int INITIAL_VELOCITY = 10;
const int WIDTH = 900;
const int HEIGHT = 450;
const string GAMEOVER = "./gameover/g.bmp";
const string START = "./start/startgame.bmp";
const string PAUSE = "./pause/pause.bmp";
const string RUN = "./character/run/";
const string BMP = ".bmp";
const string COIN = "./coin/";
const string ROCKET = "./rocket/";
const string JUMP = "./character/jump/";
const string SHOOT = "./character/shooting/";
const string GND = "./GND/gnd";
const string PIT = "Pit";
const string POINT ="./points/";

void read_map(vector <string>& Elements,vector <int>& Elements_status,vector <int>& X,vector <int>& Y);

void draw_platform (window& w);
void draw_coin (window& w,int& coin_flag,int x,int y);
void draw_rocket (window& w,int& rocket_flag,int x,int y);
void draw_character_run(window& w,int& run_flag);
void draw_character_jump(window& w,int& jump_flag);
void draw_character_shoot(window& w,int& shoot_flag);
void draw_ground(window& w,int x);
void draw_pit(window& w ,int x);
void draw_score (window& w,int point);
void draw_gameover (window& w);
void draw_start (window& w);
void draw_pause (window& w);

void handle_graphics(window& w,vector <string>& Elements,vector <int>& Elements_status,vector <int>& X,vector <int>& Y,int& coin_flag,int& rocket_flag,int& run_flag,int& jump_flag,int & shoot_flag,int point);
void handle_ground_graphics(window& w,vector <string>& Elements,vector <int>& X);

double velocity_calculator (int position);
int logarithm(int n,int base=10);
void decrease_pose (vector <int>& X,int velocity);

void gameplay(vector <string>& Elements,vector <int>& Elements_status,vector <int>& X,vector <int>& Y,int jump_flag,int shoot_flag,int& point,int position,bool& live_flag);
void generate_random_map(vector <string>& Elements,vector <int>& Elements_status,vector <int>& X,vector <int>& Y,int x_max);
int main()
{
    window w(WIDTH, HEIGHT);
    
   	
    vector <string> Elements;
    vector <int> X;
    vector <int> Y;
    vector <int> Elements_status;
    read_map(Elements,Elements_status,X,Y);
    int x_max=X[X.size()-1];
    bool live_flag=true;
    bool start_flag=0;
    bool pause_flag=1;
    bool quit = false;
    int slow_speed_counter=0;
    
    int position=0;
    int point=0;
    double v=0;
    int coin_flag=1,rocket_flag=1,run_flag=1,jump_flag=0,shoot_flag=0,slow_speed_flag=0;
    int map_gen_counter=0;
    
    draw_start(w);
    w.update_screen();
    while (!quit) {
        if (!pause_flag)
        {
            if(live_flag)
            {    
                usleep(50000);
                position+=v;
                decrease_pose(X,(int)v);
                map_gen_counter++;
                if (map_gen_counter%21==0)
                {
                    generate_random_map (Elements,Elements_status,X,Y,x_max);
                    map_gen_counter=0;
                }
                v=velocity_calculator(position);
                gameplay(Elements,Elements_status,X,Y,jump_flag,shoot_flag,point,position,live_flag);
                handle_graphics(w,Elements,Elements_status,X,Y,coin_flag,rocket_flag,run_flag,jump_flag,shoot_flag,point);
                w.update_screen();
            }    
            else
            {
                
                draw_gameover(w);
                w.update_screen();
            }                
        }  
        else
        {
            if (pause_flag==1 && start_flag==1 && live_flag==1)
            {
                draw_pause(w);
                w.update_screen();
            }
        }
            HANDLE(
                
                QUIT(quit = true);
            
                KEY_PRESS(LEFT, {
                        v/=2;
                        slow_speed_counter++;
                        if (slow_speed_counter%20==0)
                        {
                            point--;
                            slow_speed_counter=0;
                        }    

                    });
                KEY_PRESS(s, {
                        if (point>=3)
                        {
                            shoot_flag=1; 
                            jump_flag=0;
                            point-=3;
                        }
                     });           
                          
                KEY_PRESS(SPACE, {    
                        jump_flag=1;
                        shoot_flag=0;
                    });           
                KEY_PRESS(q, quit = true);
                
                KEY_PRESS(p, {    
                        
                        pause_flag=!pause_flag;
                        start_flag=1;
                    });           
                KEY_PRESS(r, {    
                        
                        
                    });     
            );
    }
    return 0; 
}
void read_map (vector <string>& Elements,vector <int>& Elements_status,vector <int>& X,vector <int>& Y)
{
    string element;
    int x,y;
    while (cin >> element)
    {
        // cout << element <<endl;
        Elements.push_back(element);
        if (element=="Coin")
        {   
            cin >> x >> y;
            X.push_back(x*UNIT);
            Y.push_back((9-y)*UNIT);
            Elements_status.push_back(1);
        }
        else
        {
            cin >> x ;
            X.push_back(x*UNIT);
            if (element=="Rocket")
                {
                    Y.push_back(ROCKET_HEIGHT);
                    Elements_status.push_back(1);
                }
            else if (element=="Pit")
                {
                    Y.push_back(GROUND_HEIGHT);           
                    Elements_status.push_back(1);
                }  
            else
            {
                // cout<< element<<"---"<<(element=="Rocket"))<<endl;
                Y.push_back(ROCKET_HEIGHT);
                Elements_status.push_back(1);
            }     
        }

    }
    // reverse (Elements.begin(),Elements.end());
    // reverse (X.begin(),X.end());
    // reverse (Y.begin(),Y.end());
}
void draw_platform (window& w)
{
	w.draw_bmp("./GND/platform.bmp",0,0); 
}
void draw_coin (window& w,int& coin_flag,int x,int y)
{
	if (coin_flag!=0)
	{
		
		w.draw_transparent_bmp(COIN+(char)((coin_flag%4)+1+DIGIT_TO_CHAR)+BMP,x,y,WHITE);
		coin_flag++;
	}
}
void draw_rocket (window& w,int& rocket_flag,int x,int y)
{
	if (rocket_flag!=0)
	{
		
		w.draw_transparent_bmp(ROCKET+(char)((rocket_flag%3)+1+DIGIT_TO_CHAR)+BMP,x,y,WHITE);
		rocket_flag++;
	}
}
void draw_character_run(window& w,int& run_flag)
{
	if (run_flag!=0)
	{
		
		w.draw_transparent_bmp(RUN+(char)((run_flag%8)+1+DIGIT_TO_CHAR)+BMP,PLAYER_POSE,RUN_HEIGHT,WHITE);
		run_flag++;
	}
}
void draw_character_jump(window& w,int& jump_flag)
{
	if (jump_flag%10!=0)
	{
		w.draw_transparent_bmp(JUMP+(char)((jump_flag%9)+1+DIGIT_TO_CHAR)+BMP,JUMP_WIDTH,JUMP_HEIGHT,WHITE);
		jump_flag++;
	}
    else
        jump_flag=0;
}

void draw_character_shoot(window& w,int& shoot_flag)
{
	if (shoot_flag%7!=0)
	{
		w.draw_transparent_bmp(SHOOT+(char)((shoot_flag%6)+1+DIGIT_TO_CHAR)+BMP,SHOOT_WIDTH,SHOOT_HEIGHT,WHITE);
		shoot_flag++;
	}
    else
        shoot_flag=0;
}
void draw_ground (window& w,int x)
{
    w.draw_transparent_bmp(GND+(char)(1+DIGIT_TO_CHAR)+BMP,x,GROUND_HEIGHT,WHITE);
}
void draw_pit(window& w,int x)
{
    w.draw_transparent_bmp(GND+(char)(3+DIGIT_TO_CHAR)+BMP,x-GROUND_WIDTH,GROUND_HEIGHT,WHITE);
    w.draw_transparent_bmp(GND+(char)(2+DIGIT_TO_CHAR)+BMP,x+PIT_WIDTH,GROUND_HEIGHT,WHITE);
                    
}
void handle_ground_graphics(window& w,vector <string>& Elements,vector <int>& X)
{
    int inpage_pit_pose [5]={0-PIT_FRONT,0-PIT_FRONT,0-PIT_FRONT,0-PIT_FRONT,0-PIT_FRONT};
    int index=0;
    for (int i=0;i<Elements.size();i++)
    {   
        if (Elements[i].compare("Pit")==0)
        {
            if (X[i]>WIDTH)
            {
                break;                
            }
            else
            {
                inpage_pit_pose[index]=X[i];
                index++;
            }
        }
    }
    for (int i=0;i<POSSIBLE_PITS_IN_PAGE;i++)
    {    
        draw_pit(w,inpage_pit_pose[i]);
    }
    
    int ground_flag=1;
    
    for (int i=1-GROUND_WIDTH;i<=WIDTH;i++)
    {
        ground_flag=1;
        for (int j=0;j<POSSIBLE_PITS_IN_PAGE;j++)
        {
            if(inpage_pit_pose[j]>0-PIT_FRONT)
            {
                if (inpage_pit_pose[j]-GROUND_WIDTH-5<=i && i<=inpage_pit_pose[j]+PIT_FRONT-1)
                {
                    ground_flag=0;   
                }
                
            }
        }
        if (ground_flag==1)
        {
            draw_ground(w,i);
            i=i+99;
        }
    }
}
double velocity_calculator (int position)
{
    double exponent=(position/2700)+1;
    double result=pow(1.15,exponent);
    result*=INITIAL_VELOCITY;
    return result;
}
void decrease_pose (vector <int>& X,int velocity)
{
    for (int i=0;i<X.size();i++)
    {
        X[i]-=velocity;
    }
}
// why pass by flags by refrence?
void handle_graphics(window& w,vector <string>& Elements,vector <int>& Elements_status,vector <int>& X,vector <int>& Y,int& coin_flag,int& rocket_flag,int& run_flag,int& jump_flag,int & shoot_flag,int point)
{
    vector <int> inpage_element_pose_x;
    vector <int> inpage_element_pose_y;
    vector <string> inpage_element;
    vector <int> status_index;
    int index=0;
    for (int i=0;i<Elements.size();i++)
    {   
        if (X[i]>WIDTH)
        {
            break;
        }
        else
        {
            inpage_element.push_back(Elements[i]);
            inpage_element_pose_x.push_back(X[i]);
            inpage_element_pose_y.push_back(Y[i]);
            status_index.push_back(i);
        }        
    }
   
    // platform
    draw_platform(w);    
    handle_ground_graphics(w,Elements,X);
    for (int i=0;i<inpage_element.size();i++)
    {
        if(inpage_element[i]=="Coin")
        {
            draw_coin(w,Elements_status[i],inpage_element_pose_x[i],inpage_element_pose_y[i]);
        }
    
        if(inpage_element[i]=="Rocket")
        {
            draw_rocket(w,Elements_status[i],inpage_element_pose_x[i],inpage_element_pose_y[i]);
        }
    }    
    // char
    if (jump_flag==0 && shoot_flag==0)
        draw_character_run(w,run_flag);
    else if (jump_flag!=0)
        draw_character_jump(w,jump_flag);
    else if (shoot_flag!=0)
        draw_character_shoot(w,shoot_flag);

    // score
    draw_score(w,point);
}
void gameplay(vector <string>& Elements,vector <int>& Elements_status,vector <int>& X,vector <int>& Y,int jump_flag,int shoot_flag,int& point,int position,bool& live_flag)
{
    vector <int> inpage_element_pose_x;
    vector <int> inpage_element_pose_y;
    vector <string> inpage_element;
    vector <int> status_index;
    int index=0;
    for (int i=0;i<Elements.size();i++)
    {   
        if (X[i]>WIDTH)
        {
            break;
        }
        else 
        {
            inpage_element.push_back(Elements[i]);
            inpage_element_pose_x.push_back(X[i]);
            inpage_element_pose_y.push_back(Y[i]);
            status_index.push_back(i);
        }        
    }

    for (int i=0;i<inpage_element.size();i++)
    {
        if(inpage_element[i]=="Pit")
        {
           if (PLAYER_POSE+PLAYER_WIDTH/2>=inpage_element_pose_x[i] && PLAYER_POSE<=inpage_element_pose_x[i]+PIT_WIDTH/2 && jump_flag==0)
               live_flag=false;             
        }
        if(inpage_element[i]=="Rocket")    
        {
            if(inpage_element_pose_x[i]<=PLAYER_POSE+PLAYER_WIDTH && Elements_status[i]!=0)
                live_flag=false;
            else if(shoot_flag>=3 && Elements_status[status_index[i]]!=0)
            {
                Elements_status[status_index[i]]=0;
                point+=4;
            }
        }
        if(inpage_element[i]=="Coin")    
        {
            if (PLAYER_POSE<=inpage_element_pose_x[i] && PLAYER_POSE>=inpage_element_pose_x[i]-COIN_WIDTH/2)
            {    
                if(inpage_element_pose_y[i]>=HEIGHT-PLAYER_HEIGHT-COIN_HEIGHT+10 && Elements_status[status_index[i]]!=0)
                {
                    Elements_status[status_index[i]]=0;
                    point += COIN_POINT;
                }    
                else if(jump_flag!=0 && Elements_status[status_index[i]]!=0)
                {
                    Elements_status[status_index[i]]=0;
                    point += COIN_POINT;
                }
            }
        }
    
    }
}
int logarithm (int n,int base)
{
    int result=0;
    while(n/base)
    {
        result++;
        n/=base;
    }
    return result;
}
void draw_score(window& w,int point)
{
    while (point/10>0)
    {
        w.draw_transparent_bmp (POINT+(char)(point%10+DIGIT_TO_CHAR)+BMP,(SCORE_DIGIT_SIZE/2)*logarithm(point),0,WHITE);
        point/=10;
    }
    w.draw_transparent_bmp (POINT+(char)(point%10+DIGIT_TO_CHAR)+BMP,(SCORE_DIGIT_SIZE/2)*logarithm(point),0,WHITE);
}
void draw_gameover(window& w)
{
    // draw_platform(w);
    w.draw_transparent_bmp (GAMEOVER,200,0,BLACK);    
}
void draw_start (window& w)
{
    draw_platform(w);
    w.draw_transparent_bmp (START,325,200,BLACK);   
}
void draw_pause (window& w)
{
    // draw_platform(w);
    w.draw_transparent_bmp (PAUSE,-100,-150,BLACK);   
}
void generate_random_map(vector <string>& Elements,vector <int>& Elements_status,vector <int>& X,vector <int>& Y,int x_max)
{
    srand(time(0)); // use current time as seed for random generator
    int random_variable = rand();
    int random_type_var=random_variable%NUM_OF_ELEMENET_TYPES;
    if(random_type_var==0)
    {
        Elements.push_back("Coin");
        int random_y=(random_variable%100)+HEIGHT/3;
        Y.push_back(random_y);
        
    }
    else if(random_type_var==1)
    {
        Elements.push_back("Pit");
        Y.push_back(GROUND_HEIGHT);
    }
    else if(random_type_var==2)
    {
        Elements.push_back("Rocket");
        Y.push_back(ROCKET_HEIGHT);
    }
    int random_x=(random_variable%WIDTH)+WIDTH+x_max;
    X.push_back(random_x);
    Elements_status.push_back(1);
}