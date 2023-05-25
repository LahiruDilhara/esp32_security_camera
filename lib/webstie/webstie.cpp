#include "WString.h"
#include "webstie.h"

String homePage=R""(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!-- <link rel="stylesheet" href="./homepage.css"> -->
    <title>Lahiru Dilhara</title>
    <link rel="stylesheet" href="./homepage.css">
    <style>
*{
    padding: 0;
    margin: 0;
    box-sizing: border-box;
    
}
:root{
    
    --body-background-color:rgb(224, 238, 228);
    --PI:3.141592654;
    --font-color :black;
    --font-shadow: rgba(129, 136, 131, 0.28) 4px 4px 5px;
    --window-color: white;
    --window-shadow-color:rgba(129, 136, 131, 0.277) 7px 10px 20px;
    --window-border-radius:10px;
    --percentage-circle-width-and-height:8vw;
    --percentage-circle-center:calc(var(--percentage-circle-width-and-height)/2);
    --percetage-circle-stroke-width:1vw;
    --percetage-circle-radius:calc(var(--percentage-circle-center) - calc(var(--percetage-circle-stroke-width)/2));


    /* left side bar */
    --left-side-bar-top-title-first-color:rgb(114, 148, 137);
    --left-side-bar-top-title-second-color: rgb(6, 141, 134);
    --left-side-bar-top-small-display-menu-bar-color: rgb(6, 141, 134);
    
    --left-side-bar-bottom-tabs-forground-color:rgba(140, 148, 155, 0.836);
    --left-side-bar-bottom-tabs-hover-forground-color:rgb(92, 98, 102);
    --left-side-bar-bottom-tabs-active-color:rgba(98, 152, 233, 0.178);
    --left-side-bar-bottom-tabs-active-shadow: rgba(192, 201, 209, 0.544) -7px 5px 15px;
    --left-side-bar-bottom-tabs-active-before-color:rgba(127, 140, 255, 0.938);
    --left-side-bar-bottom-tabs-small-display-box-shadow:rgba(129, 136, 131, 0.277) 2px 10px 5px;

    /* main panel header secion */
    --main-panel-header-secion-clicked-color:black;
    --main-panel-header-secion-non-clicked-color:white;
    --main-panel-header-secion-clicked-forground-color:white;
    --main-panel-header-secion-non-clicked-forground-color:black;

    --percentage-circles-outer-box-shadow: 7px 7px 10px -1px rgba(0,0,0,0.15),
                                     -7px -7px 10px -1px rgba(255,255,255,0.7);   
    --percentage-cirles-inner-box-shadow: inset 4px 4px 7px -1px rgba(0,0,0,0.2),
                                            inset -4px -4px 7px -1px rgba(255,255,255,0.7),
                                            -0.5px -0.5px 0px rgba(255,255,255,1),
                                            0.5px 0.5px 0px rgba(0,0,0,0.15),
                                            0px 12px 10px -10px rgba(0,0,0,0.05);

    --percentage-cirles-end-value-of-capacity-at-0:#e91e63;
    --percentage-cirles-end-value-of-capacity-at-100:#673ab7;
    --percentage-value-color:#555;
    --console-consolebuttons-color:#60b0ff;
    --console-consolebuttons-color:linear-gradient(to right bottom,#7bbaface,70%,rgba(114, 128, 247, 0.692));
    --console-consolebuttons-click-color:#116eca;
    --console-consolebuttons-click-color:linear-gradient(to right bottom,#3e9efd,rgb(0, 18, 185));
    --console-consolebuttons-shadow:rgb(0, 0,0, 0.4) 4px 4px 10px;
    --console-consolebuttons-click-shadow:rgb(0, 0,0, 0.7) 0px 0px 10px;
    --console-consolebuttons-forground-color:white;

    --sidebarright-heading-background-color:rgba(115, 7, 165, 0.87);
    --sidebarright-tabs-background-color:rgba(20, 207, 231, 0.562);
    --sidebarright-tabs-span-background-color:rgba(41, 20, 231, 0.363);

    --main-panel-control-section-camera-state-running-color:rgba(0, 255, 0, 0.753);
    --main-panel-control-section-camera-state-running-box-shadow:rgba(0, 255, 0, 0.98) 2px 2px 20px;
    --main-panel-control-section-camera-state-stop-color:rgba(255, 0, 0, 0.671);
    --main-panel-control-section-camera-state-stop-box-shadow:rgba(255, 0, 0, 0.863) 2px 2px 20px;

}
.dark_theme{
    --body-background-color:#17191d;
    --font-color :rgba(255, 255, 255, 0.89);
    --font-shadow: rgb(9, 10, 9) 4px 4px 5px;
    --window-color: #202528;
    --window-shadow-color:rgba(0, 0, 0, 0.952) 7px 10px 20px;

    --left-side-bar-top-title-first-color:rgb(143, 0, 156);
    --left-side-bar-top-title-second-color: rgb(73, 5, 161);
    --left-side-bar-top-small-display-menu-bar-color: rgb(73, 5, 161);

    --left-side-bar-bottom-tabs-forground-color:rgb(177, 205, 247);
    --left-side-bar-bottom-tabs-hover-forground-color:rgb(91, 35, 243);
    --left-side-bar-bottom-tabs-active-color:rgba(5, 39, 90, 0.596);
    --left-side-bar-bottom-tabs-active-shadow: rgb(20, 20, 22) -7px 5px 15px;
    --left-side-bar-bottom-tabs-active-before-color:rgba(91, 26, 196, 0.938);
    --left-side-bar-bottom-tabs-small-display-box-shadow:rgb(9, 10, 9) 2px 10px 5px;

    --main-panel-header-secion-clicked-color:rgba(83, 0, 109, 0.562);
    --main-panel-header-secion-non-clicked-color:rgba(118, 7, 122, 0.486);
    --main-panel-header-secion-clicked-forground-color:rgba(159, 15, 255, 0.582);
    --main-panel-header-secion-non-clicked-forground-color:rgba(227, 13, 255, 0.541);

    --percentage-circles-outer-box-shadow: 7px 7px 10px -1px rgba(53, 51, 51, 0.15),
                                     -7px -7px 10px -1px rgba(3, 2, 2, 0.7);   
    --percentage-cirles-inner-box-shadow: inset 4px 4px 7px -1px rgba(0,0,0,0.2),
                                            inset -4px -4px 7px -1px rgba(12, 9, 9, 0.7),
                                            -0.5px -0.5px 0px rgb(15, 11, 11),
                                            0.5px 0.5px 0px rgba(0,0,0,0.15),
                                            0px 12px 10px -10px rgba(24, 22, 22, 0.05);
    
    --percentage-cirles-end-value-of-capacity-at-0:rgba(0, 0, 0, 0.849);
    --percentage-cirles-end-value-of-capacity-at-100:#622dbd;
    --percentage-value-color:#ffffff;
    
    --console-consolebuttons-color:linear-gradient(to bottom ,#390096be,40%,rgba(0, 0, 0, 0.61));
    --console-consolebuttons-click-color:linear-gradient(to bottom ,#2801688f,40%,rgba(0, 0, 0, 0.61));
    --console-consolebuttons-shadow:rgb(0, 0, 0) 4px 4px 10px;
    --console-consolebuttons-click-shadow:rgb(0, 0,0, 0.7) 4px 4px 10px;

    --sidebarright-heading-background-color:rgba(0, 11, 110, 0.301);
    --sidebarright-tabs-background-color:rgba(32, 2, 87, 0.295);
    --sidebarright-tabs-span-background-color:rgba(70, 0, 60, 0.322);

    --main-panel-control-section-camera-state-running-color:rgba(2, 94, 2, 0.452);
    --main-panel-control-section-camera-state-running-box-shadow:rgba(0, 0, 0, 0.98) 2px 2px 20px;
    --main-panel-control-section-camera-state-stop-color:rgba(155, 0, 0, 0.548);
    --main-panel-control-section-camera-state-stop-box-shadow:rgb(0, 0, 0) 2px 2px 20px;
}
body{
    background-color: var(--body-background-color);
    display: flex;
    flex-direction: row;
    color: var(--font-color);
    
}
#menubar{
    display: none;
}
aside{
    display: inline-flex;
    margin: 0vh 0.7vw;
    flex-direction: column;
    width: 14vw;
    height: 100vh;
}
aside #sidebartop{
    background-color: var(--window-color);
    position: relative;
    height: 7vh;
    top: 1vh;
    padding: 1vw;
    white-space: nowrap;
    box-shadow: var(--window-shadow-color);
    border-radius: var(--window-border-radius);
    font-family: 'Times New Roman', Times, serif;
    font-size: 0.85vw;
    text-transform: uppercase;
    text-shadow: var(--font-shadow);
    color: var(--left-side-bar-top-title-second-color);
}

aside #sidebartopname{
    color: var(--left-side-bar-top-title-first-color);
}
aside .sidebardown{
    background-color: var(--window-color);
    display: flex;
    flex-direction: column;
    position: relative;
    align-items: center;
    top: 7vh;
    height: 84vh;
    width: 14vw;
    box-shadow: var(--window-shadow-color);
    border-radius: var(--window-border-radius);
    overflow: hidden;
}

aside .sidebartabs{
    display: inline-block;
    position: relative;
    width: 100%;
    margin: 2.5vh 0;
    padding: 2.9vh 4vw;
    border-radius: 20px;
    font-family:'Courier New', Courier, monospace;
    text-decoration: none;
    color: var(--left-side-bar-bottom-tabs-forground-color);
    font-weight: 900;
    font-size: 1vw;
    text-align: center;
    transition: transform 280ms ease-out,color 280ms ease-out,font-size 280ms ease-out;
    overflow: hidden;
    text-shadow: var(--font-shadow);
}

aside .sidebartabs:hover{
    transform: translateX(15px);
    color: var(--left-side-bar-bottom-tabs-hover-forground-color);
    font-size: 1.1vw;
}

.sidebaractive{
    background-color:  var(--left-side-bar-bottom-tabs-active-color);
    transform: translateX(15px);
    box-shadow: var(--left-side-bar-bottom-tabs-active-shadow);
}
.sidebaractive::before{
    display: block;
    position: absolute;
    left: 10px;
    top: 17px;
    border-radius: 20px;
    content: " ";
    width: 4%;
    height: 55%;
    background-color:var(--left-side-bar-bottom-tabs-active-before-color);
    box-shadow:var(--window-shadow-color);
    
}
/* main section */
main{
    width: 85vw;
    height: 100vh;
    margin-left:1vw;
    display: flex;
    justify-content: space-between;
}

/* main secion middle part */
main #middlesecion{
    width: 70%;
    margin-top: 4vh;
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
}

/* main middle header section */
main #middlesecion #header{
    padding: 0.5%;
    width: 100%;
    font-size: 1.79vw;
    display: flex;
    justify-content: space-between;
}
main #middlesecion #header #heading{
    font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif;
    font-weight: bolder;
    text-shadow: var(--font-shadow);
}
main #middlesecion #header button{
    background-color: var(--main-panel-header-secion-non-clicked-color);
    margin-left: auto;
    border: none;
    padding: 0.7vh 0.7vw;
    border-radius: var(--window-border-radius);
    font-weight: 700;
    text-shadow: var(--font-shadow);
    box-shadow: var(--window-shadow-color);
    position: relative;
    transition: transform 150ms ease-in;
    color: var(--main-panel-header-secion-non-clicked-forground-color);
}
main #middlesecion #header button:hover{
    transform: translateX(2px);
    transform: translateY(2px);
    cursor: pointer;
}

main #middlesecion #header button.buttonactive{
    background-color: var(--main-panel-header-secion-clicked-color);
    color: var(--main-panel-header-secion-clicked-forground-color);
}

/* main middle percentage tab section */

main #middlesecion #percentagetabs{
    padding-top: 2.9%;
    width: 100%;
    display: flex;
    align-items: center;
    justify-content: space-evenly;
}

main #middlesecion #percentagetabs .percentagetabbar{
    background-color: var(--window-color);
    box-shadow: var(--window-shadow-color);
    border-radius: var(--window-border-radius);
    height: 100%;
    width: 45%;
    padding: 5.5vh 7vw;
    display: flex;
    align-items: center;
    overflow: hidden;
    justify-content: space-evenly;
    position: relative;
    transition: transform 150ms ease-in;
}
main #middlesecion #percentagetabs .percentagetabbar:hover{
    transform: translateX(4px);
    transform: translateY(4px);
}

main #middlesecion #percentagetabs .percentagetabbar .titles{
    padding-right: 10%;
    white-space: nowrap;
    text-shadow: var(--font-shadow);
}
main #middlesecion #percentagetabs .percentagetabbar .titles .heading{
    font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
    padding: 15% 0px;
    font-weight: 900;
    font-size: 1vw;
}
main #middlesecion #percentagetabs .percentagetabbar .titles .value{
    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    font-size: 2vw;
}
main #middlesecion #percentagetabs .percentagetabbar .percentagebar{
    display: flex;
    align-items: center;
    justify-content: space-around;
    position: relative;
}
main #middlesecion #percentagetabs .percentagetabbar .percentagebar .outer{
    padding: 5%;
    width: var(--percentage-circle-width-and-height);
    height: var(--percentage-circle-width-and-height);
    border-radius: 50%;
    display: flex;
    align-items: center;
    justify-content: center;
    box-shadow: var(--percentage-circles-outer-box-shadow);
}
main #middlesecion #percentagetabs .percentagetabbar .percentagebar .inner{
    width: calc(var(--percentage-circle-width-and-height) - calc(var(--percetage-circle-stroke-width) * 2));
    height: calc(var(--percentage-circle-width-and-height) - calc(var(--percetage-circle-stroke-width) * 2));
    border-radius: 50%;
    box-shadow: var(--percentage-cirles-inner-box-shadow);
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 1vw;
}
main #middlesecion #percentagetabs .percentagetabbar .percentagebar .inner .number{
    font-weight: 600;
    color: var(--percentage-value-color);
}
main #middlesecion #percentagetabs .percentagetabbar .percentagebar circle {
    fill: none;
    stroke: url(#GradientColor);
    stroke-width: var(--percetage-circle-stroke-width);
    /*stroke-dasharray: 472; 472 is the complete value */
    stroke-dasharray: calc( 2 * var(--PI) * var(--percetage-circle-radius) );
}


main #middlesecion #percentagetabs .percentagetabbar .percentagebar svg{
    position: absolute;
}
main #middlesecion #percentagetabs .percentagetabbar .percentagebar svg .circle1{
    stroke-dashoffset: calc( 2 *  var(--PI) * var(--percetage-circle-radius) * 0.5 );
}
main #middlesecion #percentagetabs .percentagetabbar .percentagebar svg .circle2{
    stroke-dashoffset: calc( 2 *  var(--PI) * var(--percetage-circle-radius) * 0.25 );
}

/* main middle console section  */

main #middlesecion #console{
    background-color: var(--window-color);
    margin: 4vh 0vh;
    box-shadow: var(--window-shadow-color);
    border-radius: var(--window-border-radius);
    display: flex;
    width: 57vw;
    flex-direction: column;
    align-items: center;
    justify-content: space-evenly;
}

main #middlesecion #console #state{
    font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif;
    font-size: 2.5vw;
    font-weight: 900;
    text-shadow: var(--font-shadow);
    text-transform: capitalize;
    padding-top: 9vh;
    padding-bottom: 4vw;
    width: 38vw;
    white-space: nowrap;
    display: flex;
    align-items: center;
    justify-content: space-between;
    text-transform: uppercase;
}
main #middlesecion #console #state span{
    padding: 2vh 2vw;
    position: relative;
    font-size: 2vw;
    border-radius: var(--window-border-radius);
    box-shadow: var(--main-panel-control-section-camera-state-running-box-shadow);
    background-color: var(--main-panel-control-section-camera-state-running-color);
    width: 14vw;
    text-align: center;
}

main #middlesecion #console #consolebuttons{
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding: 7vh 0vh;
    width: 34vw;
}

main #middlesecion #console #consolebuttons button{
    border: none;
    display: block;
    background: var(--console-consolebuttons-color);
    padding: 2.9vh 4vw;
    border-radius: var(--window-border-radius);
    box-shadow: var(--console-consolebuttons-shadow);
    font-size: 2vw;
    text-transform: uppercase;
    text-shadow: var(--font-shadow);
    font-weight: 900;
    color: var(--console-consolebuttons-forground-color);
    transition: transform 200ms ease-in;
}
main #middlesecion #console #consolebuttons button:hover{
    transform: translateX(5px);
    transform: translateY(5px);
    cursor: pointer;
}
main #middlesecion #console #consolebuttons button:active{
    background: var(--console-consolebuttons-click-color);
    box-shadow: var(--console-consolebuttons-click-shadow);
}

/* main secion right side bar */
main #rightsidebar{
    position: relative;
    top: 4vh;
    width: 30%;
    height: 98vh;
    margin: 0.01vw;
    display: flex;
    flex-direction: column;
    justify-content: space-evenly;
}

main #rightsidebar .rightsidebartab{
    height: 44vh;
    position: relative;
    left: 1vw;
    width: 85%;
    margin-bottom: 2hv;
    padding: 2.2vw;
    background-color: var(--window-color);
    box-shadow: var(--window-shadow-color);
    border-radius: var(--window-border-radius);
    box-shadow: var(--window-shadow-color);
    border-radius: var(--window-border-radius);
    display: flex;
    align-items: center;
    flex-direction: column;
}
main #rightsidebar .rightsidebartab .header{
    text-align: center;
    font-size: 1.4vw;
    position: relative;
    top: -2.4vh;
    color: var(--font-color);
    font-weight: 900;
    padding: 0.4vw 4.5vw;
    text-transform: uppercase;
    background-color: var(--sidebarright-heading-background-color);
    border-radius: var(--window-border-radius);
    box-shadow: var(--window-shadow-color);
}
main #rightsidebar .rightsidebartab .tabwindow{
    overflow-x: scroll;
    display: flex;
    flex-direction: column;
    align-items: center;
    width: 20vw;
}
main #rightsidebar .rightsidebartab .tabwindow div{
    background-color: var(--sidebarright-tabs-background-color);
    border-radius: var(--window-border-radius);
    box-shadow: var(--window-shadow-color);
    text-align: center;
    font-family: 'Courier New', Courier, monospace;
    font-size: 1vw;
    font-weight: 700;
    padding: 0.2vw;
    text-shadow: var(--font-shadow);
    margin-bottom: 2.45vh;
    transition: transform 200ms ease-in;
    display: flex;
    align-items: center;
    justify-content: space-evenly;
    width: 16.8vw;
}
main #rightsidebar .rightsidebartab .tabwindow div:hover{
    transform: scale(1.2);
    transform: translateX(-10px);
}
main #rightsidebar .rightsidebartab .tabwindow div span{
    background-color: var(--sidebarright-tabs-span-background-color);
    box-shadow: var(--window-shadow-color);
    border-radius: var(--window-border-radius);
    padding: 0.49vw;
}
@media (max-width: 1500px) and (min-width:1000px) {
    aside{
        height: 114vh;
    }
    aside .sidebardown{
        height: 114vh;
    }
    main{
        display: flex;
        flex-direction: column;
    }
    main #middlesecion{
        margin: 0;
        padding: 2%;
        width: 100%;
    }
    main #middlesecion #percentagetabs .percentagetabbar{
        padding: 2.5vw 0vw;
    }
    main #middlesecion #percentagetabs .percentagetabbar .titles{
        padding: 0;
    }
    main #middlesecion #console{
        width: 70%;
    }
    main #middlesecion #console #state{
        padding: 4vh 0;
    }
    main #middlesecion #console #consolebuttons{
        padding: 2vh 0;
        padding-bottom: 5vh;
    }
    main #rightsidebar{
        flex-direction: row;
        width: auto;
        height: auto;
        top: 0;
    }
    main #rightsidebar .rightsidebartab{
        width: auto;
        height: 40vh;
    }
}
@media (max-height: 1024px) and (max-width: 600px) and (min-height: 0px) and (min-width: 0px){
    body{
        flex-direction: column;
    }
    aside{
        position: absolute;
        margin: 0;
    }
    aside #sidebartop{
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        display: flex;
        font-size: 2vw;
        border-radius: 0;
        height: 12.5vh;
        z-index: 5;
        /* background-color: red; */
    }
    aside #sidebartop h1{
        font-size: 0;
    }
    #menubar{
        display: block;
        width: 5.9vw;
        height: 4vh;
        position: relative;
        top: 65%;
        left: 7%;
        transition: transform 250ms ease-in;
    }
    #smallscreenmenubar{
        display: block;
        width: 100%;
        height: 10%;
        background-color: var(--left-side-bar-top-small-display-menu-bar-color);
        border-radius: 25%;
        transition: width 250ms ease-in;
    }
    #smallscreenmenubar::before{
        content: "";
        display: block;
        position: absolute;
        width: 100%;
        height: 10%;
        top: 9px;
        border-radius: 25%;
        background-color: var(--left-side-bar-top-small-display-menu-bar-color);
        transition:  transform 250ms ease-in;
    }
    #smallscreenmenubar::after{
        content: "";
        display: block;
        position: absolute;
        width: 100%;
        height: 10%;
        top: -9px;
        border-radius: 25%;
        background-color: var(--left-side-bar-top-small-display-menu-bar-color);
        left: 0%;
        transition:  transform 250ms ease-in;
    }
    #menubar:hover{
        transform: translateY(4px);
        cursor: pointer;
    }
    #menubar.active #smallscreenmenubar{
        width: 0;
    }
    #menubar.active #smallscreenmenubar::before{
        transform: rotate(45deg) translateY(-12.9px);
    }
    #menubar.active #smallscreenmenubar::after{
        transform: rotate(-45deg) translateY(12.9px);
    }

    aside .sidebardown{
        border-radius: 0%;
        position: fixed;
        box-shadow:  var(--left-side-bar-bottom-tabs-small-display-box-shadow);
        top: 12.5vh;
        height: 91%;
        width: 40vw;
        transition: transform 400ms ease-out;
        z-index: 10;
        /* transform: translateX(-10vw); */
    }
    aside .sidebartabs{
        font-size: 2.5vw;
        padding: 2.2vh;
    }
    aside .sidebartabs:hover{
        font-size: 2.9vw;
    }
    .sidebaractive::before{
        left: 2vw;
        top: 1.7vh;
        width: 4%;
        height: 48%;
    }
    .sidebaractivesmallscreenclass{
        transform: translateX(-40vw);
        box-shadow: none;
    }
    main{
        position: absolute;
        top: 11vh;
        margin: 0;
        width: 100%;
        flex-direction: column;
    }
    main #middlesecion{
        width: 100%;
        margin: 2vh 0;
    }
    main #middlesecion #header{
        position: fixed;
        top: 1vh;
        right: 2vw;
        width: 95%;
        z-index: 5;
    }
    main #middlesecion #heading{
        font-size: 5vw;
    }
    main #middlesecion #header button{
        position: relative;
        top: 2vh;
        right:4vw;
    }
    main #middlesecion #percentagetabs{
        flex-direction: column;
        margin: 0;
    }
    main #middlesecion #percentagetabs .percentagetabbar{
        width: 85%;
        margin-bottom: 2.9vh;
        flex-direction: row;
        justify-content: space-evenly;
        padding: 5vw;
    }
    main #middlesecion #percentagetabs .percentagetabbar .titles {
        padding: 0;
    }
    main #middlesecion #percentagetabs .percentagetabbar .titles .heading{
        font-size: 4.5vw;
    }
    main #middlesecion #percentagetabs .percentagetabbar .titles .value{
        font-size: 2.8vw;
    }
    main #middlesecion #percentagetabs .percentagetabbar .percentagebar{
        --percentage-circle-width-and-height:24vw;
        --percentage-circle-center:calc(var(--percentage-circle-width-and-height)/2);
        --percetage-circle-stroke-width:2.7vw;
        --percetage-circle-radius:calc(var(--percentage-circle-center) - calc(var(--percetage-circle-stroke-width)/2));
    }
    main #middlesecion #percentagetabs .percentagetabbar .percentagebar .inner .number{
        font-size: 2.9vw;
    }
    main #middlesecion #console{
        margin: 0;
        width: 85%;
    }
    main #middlesecion #console #state{
        font-size: 5vw;
        width: 100%;
        justify-content: space-evenly;
        padding-top: 4vh;
    }
    main #middlesecion #console #state span{
        padding: 1.8vh 4.5vw;
        font-size: 2vw;
        font-size: 2.5vw;
        width: 21vw;
    }
    main #middlesecion #console #consolebuttons{
        padding-top: 4vh;
        padding-bottom: 5vh;
        width: 100%;
        justify-content: space-evenly;
    }
    main #middlesecion #console #consolebuttons button{
        padding: 2vh 5.9vw;
        font-size: 2.7vw;
    }
    main #rightsidebar{
        width: 100%;
        flex-direction: column;
        justify-content: center;
        align-items: center;
    }
    main #rightsidebar .rightsidebartab{
        padding: 2vw;
        margin-bottom: 4vh;
    }
    main #rightsidebar .rightsidebartab .header{
        top: 0;
        font-size: 5vw;
        padding: 1vw 20vw;
    }
    main #rightsidebar .rightsidebartab .tabwindow{
        width: 80vw;
        width: 100%;
        /* padding: 2vw; */
        margin: 4vw;
    }
    main #rightsidebar .rightsidebartab .tabwindow div{
        width: 65vw;
        padding: 2vw;
        font-size: 4vw;
    }
}
    </style>
</head>
<body>
    <aside id="sidebar">
        <div id="sidebartop">
            <h1><span id="sidebartopname">Lahiru</span> Dilhara</h1>
            <div id="menubar">
                <div id="smallscreenmenubar"></div>
            </div>
        </div>
        <div class="sidebardown sidebaractivesmallscreenclass">
            <a href="#" class="sidebartabs sidebaractive" id="dashboard" >Dashboard</a>
            <a href="#" class="sidebartabs" id="developer">Developer</a>
            <a href="#" class="sidebartabs" id="settings">Settings</a>
            <a href="#" class="sidebartabs" id="settings">Logout</a>
        </div>
    </aside>
    <main>
        <div id="middlesecion">
            <div id="header">
                <div id="heading">Dashboard</div>
                <div>
                    <button class="mainheaderbuttons buttonactive" id="light">Light</button>
                    <button class="mainheaderbuttons" id="dark">Dark</button>
                </div>
            </div>
            <div id="percentagetabs">
                <div class="percentagetabbar">
                    <div class="titles">
                        <h4 class="heading">Total Capacity</h4>
                        <h4 class="value" id="totalcapacityinmb">74MB</h4>
                        <h4 class="heading">Used Capacity</h4>
                        <h4 class="value" id="usedcapacityinmb">74MB</h4>
                    </div>
                    <div class="percentagebar">
                        <svg xmlns:"http://www.w3.org/2000/svg" version="1.1" id="svgwidth" width="var(--percentage-circle-width-and-height)" height="var(--percentage-circle-width-and-height)">
                            <defs>
                                <linearGradient id="GradientColor">
                                    <stop offset="0%" stop-color="var(--percentage-cirles-end-value-of-capacity-at-0)"/>
                                    <stop offset="100%" stop-color="var(--percentage-cirles-end-value-of-capacity-at-100)"/>
                                </linearGradient>
                            </defs>
                            <circle id="circle1" class="circle1" cx="var(--percentage-circle-center)" cy="var(--percentage-circle-center)" r="var(--percetage-circle-radius)" stroke-linecap="round" style="--percentage:200" id="circle1"/>
                        </svg>
                        <div class="outer">
                            <div class="inner">
                                <div class="number" id="usedspacepercentage">
                                    45%
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="percentagetabbar">
                    <div class="titles">
                        <h4 class="heading">Usable Capacity</h4>
                        <h4 class="value" id="usablecapacityinmb">55MB</h4>
                        <h4 class="heading">Free Capacity</h4>
                        <h4 class="value" id="freecapacityinmb">280GB</h4>
                    </div>
                    <div class="percentagebar">
                        <svg xmlns:"http://www.w3.org/2000/svg" version="1.1" width="var(--percentage-circle-width-and-height)" height="var(--percentage-circle-width-and-height)">
                            <circle id="circle2" class="circle2" cx="var(--percentage-circle-center)" cy="var(--percentage-circle-center)" r="var(--percetage-circle-radius)" stroke-linecap="round" style="--percentage:100"/>
                        </svg>
                        <div class="outer">
                            <div class="inner">
                                <div class="number" id="freespacepercentage">
                                    75%
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div> <!--used capacity and free capacity-->
            <div id="console">
                <div id="state">Camera State <span id="stateofcamera">Running</span></div>
                <div id="consolebuttons">
                    <button id="start" class="consolebutton">Start</button>
                    <button id="format" class="consolebutton">Format</button>
                    <button id="stop" class="consolebutton">Stop</button>
                </div>
            </div>
        </div>
        <div id="rightsidebar">
            <div id="sdcard" class="rightsidebartab">
                <div class="header">Sd Card</div>
                <div class="tabwindow">
                    <div>Sd Card type <span>SDHC</span></div>
                    <div>Sd Card Format <span>FAT32</span></div>
                    <div>Sd Card Size <span>4GB</span></div>
                    <div>Sd Card Used <span>2GB</span></div>
                    <div>Sd Card Free <span>2GB</span></div>
                </div>
            </div>
            <div id="camera" class="rightsidebartab">
                <div class="header">Camera</div>
                <div class="tabwindow">
                    <div>Camera resolution <span>1024x720</span></div>
                    <div>JPEG Quality <span>10</span></div>
                    <div>Pixel Format <span>JPEG</span></div>
                    <div>Frame Buffer <span>2</span></div>
                    <div>Clock Frequency <span>500000</span></div>
                    <div>JPEG Quality <span>10</span></div>
                </div>
            </div>
        </div> <!--sd card details and camera details-->
    </main>

    <script defer>
        const PI = 3.141592654;
        const startbutton = document.getElementById("start");
        const endbutton = document.getElementById("stop");
        const format_= document.getElementById("format");
        const stateheader = document.getElementById("stateofcamera");
        const tablist = document.querySelectorAll('.sidebartabs');
        const buttonlist = document.querySelectorAll('.mainheaderbuttons');
        const smallscreenmenubar_ = document.getElementById("menubar");
        const usedCapacityCircle=document.getElementById("circle1");
        const freeCapacityCircle=document.getElementById("circle2");
        const usedCapacityCircleprecentage = document.getElementById("usedspacepercentage");
        const freeCapacityCircleprecentage = document.getElementById("freespacepercentage");

        window.addEventListener('resize',()=>{
            location.reload();
        });

        tablist.forEach(tab =>{
            tab.addEventListener('click',()=>{
                document.querySelector('.sidebaractive')?.classList.remove('sidebaractive');
                tab.classList.add('sidebaractive');
            })
        })

        buttonlist.forEach(tab =>{
            tab.addEventListener('click',()=>{
                document.querySelector('.buttonactive')?.classList.remove('buttonactive');
                tab.classList.add('buttonactive');
            })
        });
        const darkthemebutton = document.querySelector("#dark");
            darkthemebutton.addEventListener('click',()=>{
                document.body.classList.add("dark_theme");
            })
        const lighthemebutton = document.querySelector("#light");
            lighthemebutton.addEventListener('click',()=>{
                document.body.classList.remove("dark_theme");
            })
        document.querySelectorAll(".sidebartabs").forEach(tab=>{
            tab.addEventListener('click',()=>{
                document.getElementById("heading").innerHTML=tab.innerHTML;
            })
        })
        smallscreenmenubar_.addEventListener('click',()=>{
            document.querySelector(".sidebardown").classList.toggle('sidebaractivesmallscreenclass');
            smallscreenmenubar_.classList.toggle("active")
        });

        // 

        console.log(usedCapacityCircle);
        console.log(freeCapacityCircle);

        fetch("/state").then(response=>response.text()).then(data=>{
            console.log(data);
            stateheader.innerHTML=""+data;
            if(data.includes("running")){
                stateheader.style.backgroundColor="var(--main-panel-control-section-camera-state-running-color)";
                stateheader.style.boxShadow="var(--main-panel-control-section-camera-state-running-box-shadow)";
            }
            else if(data.includes("stop")){
                stateheader.style.backgroundColor="var(--main-panel-control-section-camera-state-stop-color)";
                stateheader.style.boxShadow="var(--main-panel-control-section-camera-state-stop-box-shadow)";
            }
        })

        startbutton.addEventListener("click",()=>{
            fetch("/start").then(response=>response.text()).then(data => {console.log(data);stateheader.innerHTML=""+data;stateheader.style.backgroundColor="var(--main-panel-control-section-camera-state-running-color)";stateheader.style.boxShadow="var(--main-panel-control-section-camera-state-running-box-shadow)";});
            
        });
        endbutton.addEventListener("click",()=>{
            fetch("/stop").then(response =>response.text()).then(data=>{console.log(data);stateheader.innerHTML=""+data;stateheader.style.backgroundColor="var(--main-panel-control-section-camera-state-stop-color)";stateheader.style.boxShadow="var(--main-panel-control-section-camera-state-stop-box-shadow)";});
            
        });
        format_.addEventListener("click",()=>{
            fetch("/format").then(response =>response.text()).then(data=>{console.log(data);stateheader.innerHTML=""+data});
            
        });
        function calculateDasharrayoffset(percentage_){
            percentage_ = 1 - (percentage_/100);
            const rootstyles = getComputedStyle(document.getElementsByClassName("percentagebar")[0]);
            const precentageCircleHeightAndWidth = parseInt(rootstyles.getPropertyValue("--percentage-circle-width-and-height"),10);
            const precentageCircleStrokeWidth = parseInt(rootstyles.getPropertyValue("--percetage-circle-stroke-width"),10);
            const radius = (precentageCircleHeightAndWidth/2) - (precentageCircleStrokeWidth/2);
            console.log(radius);
            return (2*PI*radius*percentage_)+"vw";
        };
        function updatePrecentage(object,precentage){
            object.innerHTML = precentage+"%";
        }
        usedCapacityCircle.style.strokeDashoffset = calculateDasharrayoffset(70);
        freeCapacityCircle.style.strokeDashoffset = calculateDasharrayoffset(50);
        updatePrecentage(usedCapacityCircleprecentage,70);
        updatePrecentage(freeCapacityCircleprecentage,50);
        

        fetch("/camerastat").then(response=>response.json()).then(data=>{
            console.log(data);
            const totalcapacity = data.totalcapacity;
            const usedcapacity = data.usedcapacity;
            const usablecapacity = data.usablecapacity;
            const freecapacity = data.freecapacity;

            document.getElementById("totalcapacityinmb").innerHTML = totalcapacity+"MB";
            document.getElementById("usedcapacityinmb").innerHTML = usedcapacity+"MB";
            document.getElementById("usablecapacityinmb").innerHTML = usablecapacity+"MB";
            document.getElementById("freecapacityinmb").innerHTML = freecapacity+"MB";

            const usedcapacity_ = Math.round((usedcapacity/usablecapacity)*100);
            const freecapacity_ = Math.round((freecapacity/usablecapacity)*100);

            usedCapacityCircle.style.strokeDashoffset = calculateDasharrayoffset(usedcapacity_);
            freeCapacityCircle.style.strokeDashoffset = calculateDasharrayoffset(freecapacity_);
            updatePrecentage(usedCapacityCircleprecentage,usedcapacity_);
            updatePrecentage(freeCapacityCircleprecentage,freecapacity_);

        })
    </script>
</body>
</html>
)"";
