/************************************************************************
Filename:		CPPFinalProject.cpp
Version:		1.0
Author:			William Johns
Student Number:	040 832 509
Course Name:	C++ Programming - CST8219
Lab Section:	303
Assignment#:	Final 
Assignment name:Final Project (Simon Says)
Due Date:		9th of December 2020
Submission Date:11th of December 2020
Professor:		Eric Torunski
Purpose:		Creates a GUI that allows the user to play what is essentially the memory game "Simon Says"
                Once the user loses the game by getting the sequence of colours/notes wrong, 
                displays the amount of rounds won (times the player got the colours/notes right)
                The player also can lose the game if more than 5s pass before their next input
                User starts the game by using the new game button
                There is also a quit button
************************************************************************/
#include <iostream>
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/audio/player.hpp>
#include <nana/threads/pool.hpp>
#include <nana/gui/timer.hpp>
#include "CPPFinalProject.h" //almost unused #include <iostream> is the only thing in there, which can easily be moved

using namespace std;

//takes the current vector, gets a random int (between 0 and 3) and adds it to the back of the vector before returning it
vector<int> addVector(vector<int> current) {
    int temp = rand() % 4;
    current.push_back(temp);
    return current;
}

//declares and defines all the notes, buttons, timers, and labels so that the game of Simon Says can be played in the GUI
int main()
{
    //variables
    vector <int> currentSimon; //stores colours (as integers between 0 and 3) for the simon says
    int counter = 0; //tracks what colour user is at in the current sequence of simon says

    using namespace nana;

    //define timers
    timer myTimer(std::chrono::milliseconds(5000)); //set the time to 5s, ensures user inputs a new colour before 5s expire
    timer goThrough(std::chrono::milliseconds(500)); //small delay so that you have time to unclick the start button

    //define notes
    audio::player playerDo("Do_Piano.wav");
    audio::player playerRe("Re_Piano.wav");
    audio::player playerMi("Mi_Piano.wav");
    audio::player playerFa("Fa_Piano.wav");
    audio::player playerSol("Sol_Piano.wav");
    audio::player playerLa("La_Piano.wav");
    audio::player playerSi("Si_Piano.wav");
    audio::player playerDoOctave("Do_Octave_Piano.wav");
    threads::pool pool(1);

    //Define a form.
    form fm;

    //Define a label and display a text.
    label lab{ fm, "<bold>Simon Says</>" };
    lab.format(true);

    //Define a label to display the current level
    label message{ fm, "No Game Started" }; //initial display
    message.format(true);

    //Define a button and answer the click event.
    button btn{ fm, "Quit" };
    btn.events().click([&fm] {
        fm.close();
        });

    //Declare the buttons used to play 
    button redBtn{ fm, "Red" };
    button yellowBtn{ fm, "Yellow" };
    button blueBtn{ fm, "Blue" };
    button greenBtn{ fm, "Green" };
    button startBtn{ fm, "Start New Game" };

    //Define button default colours
    redBtn.bgcolor(color(255, 0, 0));
    yellowBtn.bgcolor(color(255, 255, 0));
    blueBtn.bgcolor(color(0, 0, 255));
    greenBtn.bgcolor(color(0, 255, 0));


    //Define events that happen when the button is clicked
    redBtn.events().click([&] {
        //printf("clicked Red\n");
        myTimer.stop(); //stop the timer 
        goThrough.stop(); //stop the timer
        playerDo.play(); //play the note
        if (!currentSimon.empty()) { //if a game is currently happening (will have 1+ in currentSimon)
            if (currentSimon.at(counter) == 0) { //if the current value is red(0) and correct
               if (counter == currentSimon.size() - 1) { //if last input (and also correct)
                    counter = 0; //reset the counter
                    currentSimon = addVector(currentSimon); //add to currentSimon
                    goThrough.start(); //start the goThrough colours timer
                }
                else { //not at then end of the current simon says
                    counter++; //incremnt counter
                    myTimer.start(); //restart the timer
                }
            }
            else { //not the correct colour
                char temp[100] = "";
                itoa(currentSimon.size(), temp, 10);
                char temp2[100] = "Sorry Wrong Colour,\n Your Score Was: ";
                strcat(temp2, temp);
                message.caption(temp2);
                counter = 0; //reset the counter
                currentSimon.clear(); //empty the currentSimon vector
                myTimer.stop(); //stop the timer
                playerDoOctave.play(); //play the notes associated with loosing
                playerSol.play();
                playerLa.play();
            }
        }
        });
    redBtn.events().mouse_down([&] { //when the mouse pressed down change the colour to lit
        redBtn.bgcolor(color(255, 126, 126));
        });
    redBtn.events().mouse_up([&] { //when the mouse is lifted changed the colour back to normal
        redBtn.bgcolor(color(255, 0, 0));
        });

    //Define events that happen when the button is clicked
    yellowBtn.events().click([&] {
        //printf("clicked Yellow\n");
        goThrough.stop(); //stop the timer
        myTimer.stop(); //stop the timer 
        playerRe.play(); //play the note
        if (!currentSimon.empty()) { //if a game is currently happening (will have 1+ in currentSimon)
            if (currentSimon.at(counter) == 1) { //if the current value is yellow(1) and correct
               
                if (counter == currentSimon.size() - 1) { //if last input (and also correct)
                    counter = 0; //reset the counter
                    currentSimon = addVector(currentSimon); //add to currentSimon
                    goThrough.start(); //start the goThrough colours timer
                }
                else { //not at then end of the current simon says
                    counter++; //incremnt counter
                    myTimer.start(); //restart the timer
                }
            }
            else { //not the correct colour
                char temp[100] = "";
                itoa(currentSimon.size(), temp, 10);
                char temp2[100] = "Sorry Wrong Colour,\n Your Score Was: ";
                strcat(temp2, temp);
                message.caption(temp2);
                counter = 0; //reset the counter
                currentSimon.clear(); //empty the currentSimon vector
                myTimer.stop(); //stop the timer
                playerDoOctave.play(); //play the notes associated with loosing
                playerSol.play();
                playerLa.play();
            }
        }
        });
    yellowBtn.events().mouse_down([&] { //when the mouse pressed down change the colour to lit
        yellowBtn.bgcolor(color(255, 255, 126));
        });
    yellowBtn.events().mouse_up([&] { //when the mouse is lifted changed the colour back to normal
        yellowBtn.bgcolor(color(255, 255, 0));
        });

    //Define events that happen when the button is clicked
    blueBtn.events().click([&] {
        //printf("clicked Blue\n");
        goThrough.stop(); //stop the timer
        myTimer.stop(); //stop the timer 
        playerMi.play(); //play the note
        if (!currentSimon.empty()) { //if a game is currently happening (will have 1+ in currentSimon)
            if (currentSimon.at(counter) == 2) { //if the current value is blue(2) and correct
                if (counter == currentSimon.size() - 1) { //if last input (and also correct)
                    counter = 0; //reset the counter
                    currentSimon = addVector(currentSimon); //add to currentSimon
                    goThrough.start(); //start the goThrough colours timer
                }
                else { //not at then end of the current simon says
                    counter++; //incremnt counter
                    myTimer.start(); //restart the timer
                }
            }
            else { //not the correct colour
                char temp[100] = "";
                itoa(currentSimon.size(), temp, 10);
                char temp2[100] = "Sorry Wrong Colour,\n Your Score Was: ";
                strcat(temp2, temp);
                message.caption(temp2);
                counter = 0; //reset the counter
                currentSimon.clear(); //empty the currentSimon vector
                myTimer.stop(); //stop the timer
                playerDoOctave.play(); //play the notes associated with loosing
                playerSol.play();
                playerLa.play();
            }
        }
        });
    blueBtn.events().mouse_down([&] { //when the mouse pressed down change the colour to lit
        blueBtn.bgcolor(color(126, 126, 255));
        });
    blueBtn.events().mouse_up([&] { //when the mouse is lifted changed the colour back to normal
        blueBtn.bgcolor(color(0, 0, 255));
        });

    //Define events that happen when the button is clicked
    greenBtn.events().click([&] {
        //printf("clicked Green\n");
        goThrough.stop(); //stop the timer
        myTimer.stop(); //stop the timer 
        playerFa.play(); //play the note
        if (!currentSimon.empty()) { //if a game is currently happening (will have 1+ in currentSimon)
            if (currentSimon.at(counter) == 3) { //if the current value is green(3) and correct
                if (counter == currentSimon.size() - 1) { //if last input (and also correct)
                    counter = 0; //reset the counter
                    currentSimon = addVector(currentSimon); //add to currentSimon
                    goThrough.start(); //start the goThrough colours timer
                }
                else { //not at then end of the current simon says
                    counter++; //incremnt counter
                    myTimer.start(); //restart the timer
                }
            }
            else { //not the correct colour
                char temp[100] = "";
                itoa(currentSimon.size(), temp, 10);
                char temp2[100] = "Sorry Wrong Colour, \n Your Score Was : ";
                strcat(temp2, temp);
                message.caption(temp2);
                counter = 0; //reset the counter
                currentSimon.clear(); //empty the currentSimon vector
                myTimer.stop(); //stop the timer
                playerDoOctave.play(); //play the notes associated with loosing
                playerSol.play();
                playerLa.play();
            }
        }
        });
    greenBtn.events().mouse_down([&] { //when the mouse pressed down change the colour to lit
        greenBtn.bgcolor(color(126, 255, 126));
        });
    greenBtn.events().mouse_up([&] { //when the mouse is lifted changed the colour back to normal
        greenBtn.bgcolor(color(0, 255, 0));
        });

    //Define what to do when the start new game button is clicked
    startBtn.events().click([&] {
        myTimer.stop(); //stop the timer 
        message.caption("New Game"); //update the message
        currentSimon.clear(); //empty the vector
        counter = 0; //set the current counter to 0
        currentSimon = addVector(currentSimon); //add one the vector
        goThrough.start(); //display the current Simon says
        });

    //what to do when the user doesn't press anything for 5s
    myTimer.elapse([&] {
        //printf("been over 5s\n");
        char temp[100] = "";
        itoa(currentSimon.size(), temp, 10);
        char temp2[100] = "Sorry, Out of Time \nYour Score Was "; 
        strcat(temp2, temp);
        message.caption(temp2); //display that the user is out of time
        myTimer.stop(); //stop the timer
        currentSimon.clear(); //empty the vector
        counter = 0; //reset the counter
        playerDoOctave.play(); //play the game over notes
        playerSol.play();
        playerLa.play();
        });

    //called after starting a new game or after all successful inputs are inputted with a short delay 
    goThrough.elapse([&] {
      //  printf("in goThrough\n"); //works and correctly displays colours  
        myTimer.stop(); //stop the timer (if it hasn't already)
        goThrough.stop();
        for (int i = 0; i < currentSimon.size(); i++) { //loop through and
            switch (currentSimon.at(i)) 
            {//depending on what the current random colour is display the appropriate colour and play the correct sound
            case 0:
                redBtn.bgcolor(color(255, 126, 126));
                playerDo.play();
                redBtn.bgcolor(color(255, 0, 0));
                break;
            case 1:
                yellowBtn.bgcolor(color(255, 255, 126));
                playerRe.play();
                yellowBtn.bgcolor(color(255, 255, 0));
                break;
            case 2:
                blueBtn.bgcolor(color(126, 126, 255));
                playerMi.play();
                blueBtn.bgcolor(color(0, 0, 255));
                break;
            case 3:
                greenBtn.bgcolor(color(126, 255, 126));
                playerFa.play();
                greenBtn.bgcolor(color(0, 255, 0));
                break;
            default:
                break;
            } //end switch
        } //end for loop through the colours
        if (!currentSimon.empty()) { //to prevent accidental restarts for the timer
            myTimer.start(); //start the 5s timer for the user to give their input
        }
        });

    //Layout management
    fm.div("vert < <TITLE>  > <MESSAGE> < <> <RED> <> >  < <GREEN> <START> <BLUE> > < <> <YELLOW> <> > <QUIT>");

    fm["TITLE"] << lab;
    fm["MESSAGE"] << message;
    fm["QUIT"] << btn;
    fm["START"] << startBtn;
    fm["RED"] << redBtn;
    fm["YELLOW"] << yellowBtn;
    fm["BLUE"] << blueBtn;
    fm["GREEN"] << greenBtn;

    fm.collocate();

    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    nana::exec();

} //end main

