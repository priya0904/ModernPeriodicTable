#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>

void table();
void information();
int get_option(void);
int atomic_number(void);
int atomic_symbol(void);
int atomic_name(void);
int atomic_weight(void);
char block(int);
char property(int);
void show(int, char, char);
int search(void);
int history(void);
int characteristics(void);
int formulas(void);
int features(void);

char name[112][20] = {"Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen","Oxygen","Flourine","Neon", "Sodium", "Magnesium", "Aluminium", "Silicon", 
                      "Phosphorus", "Sulphur", "Chlorine", "Argon", "Potassium","Calcium","Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt",
                      "Nickel","Copper","Zinc","Gallium","Germanium","Arsenic","Selenium","Bromine","Krypton","Rubidium","Strontium","Yttrium","Zirconium","Niobium",
                      "Molybdenum","Technetium","Ruthenium","Rhodium","Palladium","Silver","Cadmium","Indium","Tin","Antimony","Tellurium","Iodine","Xenon", "Cesium",
                      "Barium","Lanthanum","Cerium","Praseodymium","Neodymium","Promethium","Samarium","Europium","Gadolinium","Terbium","Dysprosium","Holmium","Erbium",
                      "Thulium","Ytterbium","Lutetium","Hafnium","Tantalum","Tungsten","Rhenium","Osmium","Iridium","Platinum","Gold","Mercury","Thallium","Lead",
                      "Bismuth","Polonium","Astatine","Radon","Francium","Radium","Actinium","Thorium","Protactinium","Uranium","Neptunium","Plutonium","Americium",
                      "Curium","Berkelium","Californium","Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium","Rutherfordium","Dubnium","Seaborgium","Bohrium",
                      "Hassium","Meitnerium","Darmstadtium","Roentgenium","Copernicium"};
char symbol[112][5]={"H","He","Li","Be","B","C","N","O","F","Ne", "Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga",
                     "Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd",
                     "Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac",
                     "Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm",",Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn"};
double weight[112]={1.00,4.00,6.94,9.01,10.81,12.01,14.00,16.00,20.00,20.18,23.00,24.31,26.99,28.08,30.97,32.06,35.45,39.09,40.07,44.95,47.86,50.94,51.99,54.93,55.84,
                    58.69,58.93,63.54,65.39,69.7,72.64,74.92,78.96,79.90,83.80,85.46,87.62,88.90,91.22,92.90,95.94,98.00,101.07,102.90,106.42,107.86,112.41,114.81,
                    118.71,121.76,127.6,126.90,131.29,13.90,137.32,138.90,140.11,140.90,144.24,145.00,150.36,151.96,157.25,158.92,162.50,164.93,167.5,168.93,173.04,
                    174.96,178.49,180.94,183.84,186.20,190.23,192.21,195.07,196.97,200.59,204.38,207.20,208.98,209.00,210.00,222.00,223.00,226.00,227.00,231.03,232.03,
                    237.00,238.03,243,244,247,247,251,252,257,258,259,261,262,264,266,268,272,277,276,281,280,285};

int gd = DETECT,gm,i;
char b;
void main()
{
   int ab,i;
   char ch1,ch2;

   table()
   getch();
   cleardevice();
   information();
   cleardevice();
   history();
  cleardevice();
  charactersicts();
  cleardevice();
  formulas();
  cleardevice();
  features();
  cleardevice();

  while(1)
  {
        printf("\n @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        printf("\n 1. Search By Automic Number");
        printf("\n 2. Search By Automic Symbol");
        printf("\n 3. Search By Automic Name");
        printf("\n 4. Search By Automic Weight");
        printf("\n 5. Search By Exit");
        printf("\n Enter Your Choice : ");
        scanf("%d",&ab);

        switch(ab)
        {
           case 1:
                   i = atomic_number();
                   break;
           case 2:
                   i = atomic_symbol();
                   break;
           case 3:
                   i = atomic_name();
                   printf("%d",i);
                   break;
           case 4:
                   i = atomic_weight();
                   break;
           case 5:
                   exit(0);
                   break;
           default:
                  printf("\n Invalid Choice");

if(i == -1)
{
       system("cls");
       printf("\n Oops ! \nNo Such element present !\n");
			printf("\n Make a right choice this time !\n\n");
}
else if (i==999)
			continue;
		else
		{
			system("cls");
			ch1=block(i);
			ch2=property(i);
			show(i,ch1,ch2);
		}
		i=999;
	}
  }
  getch();

  void table()
  {
     initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
     settextstyle(0,EMPTY_FILL,5);
     setcolor(WHITE);
     outtextxy(20,10,"PERIODIC TABLE");
     setcolor(WHITE);

    //periods
    line(595,100,630,100);
    line(0,100,35,100);
    line(0,130,70,130);
    line(420,130,630,130);
    line(0,190,630,190);
    line(0,220,630,220);
    line(0,250,630,250);
    line(0,280,630,280);
    line(0,310,630,310);

    //groups
    line(0,100,0,310);
    line(35,100,35,310);
    line(70,130,70,310);
    line(105,190,105,310);
    line(140,190,140,310);
    line(175,190,175,310);
    line(210,190,210,310);
    line(245,190,245,310);
    line(280,190,280,310);
    line(315,190,315,310);
    line(350,190,350,310);
    line(385,190,385,310);
    line(420,130,420,310);
    line(455,130,455,310);
    line(490,130,490,310);
    line(525,130,525,310);
    line(560,130,560,310);
    line(595,100,595,310);
    line(630,100,630,310);

    settextstyle(0,EMPTY_FILL,1);
    setcolor(WHITE);

    outtextxy(15,90,"1");
    outtextxy(50,90,"2");
    outtextxy(85,90,"3");
    outtextxy(120,90,"4");
    outtextxy(155,90,"5");
    outtextxy(190,90,"6");
    outtextxy(225,90,"7");
    outtextxy(260,90,"8");
    outtextxy(295,90,"9");
    outtextxy(325,90,"10");
    outtextxy(360,90,"11");
    outtextxy(395,90,"12");
    outtextxy(430,90,"13");
    outtextxy(465,90,"14");
    outtextxy(500,90,"15");
    outtextxy(535,90,"16");
    outtextxy(570,90,"17");
    outtextxy(605,90,"18");

    outtextxy(10,105,"1.");
    outtextxy(10,125,"H");
    outtextxy(10,135,"3.");
    outtextxy(10,125,"Li");
    outtextxy(10,165,"11.");
    outtextxy(10,180,"Na");
    outtextxy(10,195,"19.");
    outtextxy(10,210,"K");
    outtextxy(10,225,"37.");
    outtextxy(10,240,"Rb");
    outtextxy(10,255,"55.");
    outtextxy(10,270,"Cs");
    outtextxy(10,285,"88.");
    outtextxy(10,300,"Fr");
    outtextxy(45,135,"4.");
    outtextxy(45,150,"Be");
    outtextxy(45,165,"12.");
    outtextxy(45,180,"Mg");
    outtextxy(45,195,"20.");
    outtextxy(45,225,"38.");
    outtextxy(45,240,"Sr");
    outtextxy(45,255,"56.");
    outtextxy(45,270,"Ba");
    outtextxy(45,285,"88.");
    outtextxy(45,300,"Ra");
    outtextxy(80,195,"21.");
    outtextxy(80,210,"Sc");
    outtextxy(80,225,"39.");
    outtextxy(80,240,"Y");
    outtextxy(80,255,"57.");
    outtextxy(80,270,"71.");
    outtextxy(80,285,"89.");
    outtextxy(80,300,"103.");
    outtextxy(115,195,"22.");
    outtextxy(115,210,"Ti");
    outtextxy(115,225,"40.");
    outtextxy(115,240,"Zr");
    outtextxy(115,255,"72.");
    outtextxy(115,270,"Hf");
    outtextxy(115,285,"104.");
    outtextxy(115,300,"Rf");
    outtextxy(150,195,"23.");
    outtextxy(150,210,"V");
    outtextxy(150,225,"41.");
    outtextxy(150,240,"Nb");
    outtextxy(150,255,"73.");
    outtextxy(150,270,"Ta");
    outtextxy(145,285,"105.");
    outtextxy(185,195,"24.");
    outtextxy(185,210,"Cr");
    outtextxy(185,225,"42.");
    outtextxy(185,240,"Mo");
    outtextxy(185,255,"34.");
    outtextxy(180,285,"106.");
    outtextxy(185,300,"Sg");
    outtextxy(220,195,"25.");
    outtextxy(220,210,"Mn");
    outtextxy(220,225,"43.");
    outtextxy(220,240,"Tc");
    outtextxy(220,255,"75.");
    outtextxy(225,270,"Re");
    outtextxy(215,285,"107.");
    outtextxy(220,300,"Bh");
    outtextxy(255,195,"26.");
    outtextxy(255,210,"Fe");
    outtextxy(255,225,"44.");
    outtextxy(255,240,"Ru");
    outtextxy(255,255,"76.");
    outtextxy(255,270,"Os");
    outtextxy(255,285,"108.");
    outtextxy(255,300,"Hs");
    outtextxy(290,195,"27.");
    outtextxy(290,210,"Co");
    outtextxy(290,225,"45.");
    outtextxy(290,240,"Rh");
    outtextxy(290,255,"77.");
    outtextxy(290,270,"Ir");
    outtextxy(285,285,"109.");
    outtextxy(290,300,"Mt");
    outtextxy(325,195,"28.");
    outtextxy(325,225,"46.");
    outtextxy(325,210,"Ni");
    outtextxy(325,225,"46.");
    outtextxy(325,240,"Pd");
    outtextxy(325,255,"78.");
    outtextxy(325,270,"Pt");
    outtextxy(320,285,"110.");
    outtextxy(325,300,"Ds");
    outtextxy(360,195,"29.");
    outtextxy(360,210,"Cu");
    outtextxy(360,225,"47.");
    outtextxy(360,240,"Ag");
    outtextxy(360,255,"79.");
    outtextxy(360,270,"Au");
    outtextxy(355,285,"111.");
    outtextxy(360,300,"Rg");
    outtextxy(395,195,"30.");
    outtextxy(395,210,"Zn");
    outtextxy(395,225,"48.");
    outtextxy(395,240,"Cd");
    outtextxy(395,255,"80.");
    outtextxy(395,270,"Hg");
    outtextxy(395,285,"112.");
    outtextxy(395,300,"Cn");
    outtextxy(435,135,"5.");
    outtextxy(435,150,"B");
    outtextxy(430,165,"13.");
    outtextxy(430,180,"Ai");
    outtextxy(430,195,"31.");
    outtextxy(430,210,"Ga");
    outtextxy(430,225,"49.");
    outtextxy(430,240,"In");
    outtextxy(430,255,"81.");
    outtextxy(430,270,"Ti");
    outtextxy(425,285,"113.");
    outtextxy(425,300,"Nh");
    outtextxy(465,135,"6.");
    outtextxy(465,150,"C");
    outtextxy(465,165,"14.");
    outtextxy(465,180,"Si");
    outtextxy(465,195,"32.");
    outtextxy(465,210,"Ge");
    outtextxy(465,255,"50.");
    outtextxy(465,240,"Sn");
    outtextxy(465,255,"82.");
    outtextxy(460,270,"Pb");
    outtextxy(460,285,"114.");
    outtextxy(460,300,"Fl");
    outtextxy(500,135,"7.");
    outtextxy(500,150,"N");
    outtextxy(500,165,"15.");
    outtextxy(500,180,"P");
    outtextxy(500,195,"33.");
    outtextxy(500,210,"As");
    outtextxy(500,225,"51.");
    outtextxy(500,240,"Sb");
    outtextxy(500,255,"83.");
    outtextxy(500,270,"Bi");
    outtextxy(495,285,"115.");
    outtextxy(495,300,"Uup");
    outtextxy(535,135,"8.");
    outtextxy(540,150,"O");
    outtextxy(535,165,"16.");
    outtextxy(540,180,"S");
    outtextxy(535,195,"34.");
    outtextxy(535,210,"Se");
    outtextxy(535,225,"52.");
    outtextxy(535,240,"Te");
    outtextxy(535,255,"84.");
    outtextxy(535,270,"Po");
    outtextxy(535,285,"116.");
    outtextxy(535,300,"Lv");
    outtextxy(570,165,"17.");
    outtextxy(570,180,"Cl");
    outtextxy(570,195,"35.");
    outtextxy(570,210,"Br");
    outtextxy(570,225,"53.");
    outtextxy(570,240,"I");
    outtextxy(570,255,"85.");
    outtextxy(570,270,"At");
    outtextxy(565,285,"117.");
    outtextxy(565,300,"Uus");
    outtextxy(605,105,"2.");
    outtextxy(605,120,"He");
    outtextxy(605,135,"10.");
    outtextxy(605,150,"Ne");
    outtextxy(605,165,"18.");
    outtextxy(605,180,"Ar");
    outtextxy(605,195,"36.");
    outtextxy(605,210,"Kr");
    outtextxy(605,225,"54.");
    outtextxy(605,240,"Xe");
    outtextxy(605,255,"86.");
    outtextxy(605,270,"Rn");
    outtextxy(605,285,"118.");
    outtextxy(605,300,"Uuo");

    line(105,380,630,380);
    line(105,410,630,410);
    line(105,440,630,440);
    line(105,380,630,440);
    line(140,380,140,440);
    line(175,380,175,440);
    line(210,380,210,440);
    line(245,380,245,440);
    line(280,380,280,440);
    line(315,380,315,440);
    line(350,380,350,440);
    line(385,380,385,440);
    line(420,380,420,440);
    line(455,380,455,440);
    line(490,380,490,440);
    line(525,380,525,440);
    line(560,380,560,440);
    line(595,380,595,440);
    line(630,380,630,440);

    //block name
    line(0,85,70,85);
    line(75,175,415,175);
    line(75,175,75,178);
    line(415,175,415,178);
    line(70,85,70,88);
    line(420,85,630,85);
    line(420,85,420,88);
    line(630,85,630,365);
    line(105,365,630,365);
    line(105,365,105,370);
    line(630,365,630,370);

    outtextxy(115,385,"57.");
    outtextxy(115,400,"La");
    outtextxy(115,415,"89.");
    outtextxy(115,430,"Ac");
    outtextxy(150,385,"58.");
    outtextxy(150,400,"Ce");
    outtextxy(150,415,"90.");
    outtextxy(150,430,"Th");
    outtextxy(185,385,"59.");
    outtextxy(185,400,"Pr");
    outtextxy(185,415,"91.");
    outtextxy(185,430,"Pa");
    outtextxy(220,385,"60.");
    outtextxy(220,400,"Nd");
    outtextxy(220,415,"92.");
    outtextxy(225,385,"61.");
    outtextxy(225,400,"Pm");
    outtextxy(225,415,"93.");
    outtextxy(225,430,"Np");
    outtextxy(290,385,"62.");
    outtextxy(290,400,"Sm");
    outtextxy(290,415,"94.");
    outtextxy(290,430,"Pu");
    outtextxy(325,385,"63.");
    outtextxy(325,400,"Eu");
    outtextxy(325,415,"95.");
    outtextxy(325,430,"Am");
    outtextxy(360,385,"64.");
    outtextxy(360,400,"Gd");
    outtextxy(360,415,"96.");
    outtextxy(360,430,"Cm");
    outtextxy(395,385,"65.");
    outtextxy(395,400,"Tb");
    outtextxy(395,415,"97.");
    outtextxy(395,430,"Bk");
    outtextxy(430,385,"66.");
    outtextxy(430,400,"Dy");
    outtextxy(430,415,"98.");
    outtextxy(430,430,"Cf");
    outtextxy(465,385,"67.");
    outtextxy(465,400,"Ho");
    outtextxy(465,415,"99.");
    outtextxy(465,430,"Es");
    outtextxy(500,385,"68.");
    outtextxy(500,400,"Er");
    outtextxy(495,415,"100.");
    outtextxy(500,430,"Fm");
    outtextxy(535,385,"69.");
    outtextxy(535,400,"Tm");
    outtextxy(530,415,"101.");
    outtextxy(535,430,"Md");
    outtextxy(570,385,"70.");
    outtextxy(570,400,"Yb");
    outtextxy(565,415,"102.");
    outtextxy(570,430,"No");
    outtextxy(605,385,"71.");
    outtextxy(605,400,"Lu");
    outtextxy(600,415,"103.");
    outtextxy(605,430,"Lr");
    settextstyle(0,EMPTY_FILL,1);
    setcolor(RED);
    outtextxy(8,75,"s-block");
    outtextxy(500,75,"p-block");
    outtextxy(210,165,"d-block");
    outtextxy(330,355,"f-block");
    setcolor(YELLOW);
    outtextxy(0,460,"PRESS ENTER TO CONTINUE...");

    settextstyle(0,EMPTY_FILL,1);
    setcolor(GREEN);
    outtextxy(0,390,"Lanthanides");
    outtextxy(0,420,"Actinides");
    }
void information()
{
  int a;
  printf("\n\t\t DIGITAL MODERN PERIODIC TABLE \t");
  printf("\n **********************************\n");
  printf("\n Terms Related To Periodic Table");
  printf("\n 1.Periodic Tab     \t\t\t\t 2.Element");
  printf("\n 3.Atom             \t\t\t\t 4.Nucleus");
  printf("\n 5.Proton           \t\t\t\t 6.Neutron");
  printf("\n 7.Electron         \t\t\t\t 8.Energy Level");
  printf("\n 9.Orbital          \t\t\t\t 10.Valence ELectron");
  printf("\n 11.Periods         \t\t\t\t 12.Groups");
  printf("\n 13.Ionisation      \t\t\t\t 14.Cations");
  printf("\n 15.Anion           \t\t\t\t 16.Atomic Number");
  printf("\n 17.Mass Number     \t\t\t\t 18.Metal");
  printf("\n 19.Non-Metal       \t\t\t\t 20.Metalloid");
  printf("\n 21.Alkali Family   \t\t\t\t 22.Alkali Earth Metal");
  printf("\n 23.Calchogen       \t\t\t\t 24.Halogen");
  printf("\n 25.Nobel Gas       \t\t\t\t 26.Isotope");
  printf("\n 27.Lanthanide      \t\t\t\t 28.Actinides");
  printf("\n 29.Exit");
  printf("\n **********************************\n");
  do {
      printf("\n Enter Your Choice : ");
      scanf("%d",&i);

      if(i == 1)
      {
        printf("\n Periodic Table :- The periodic table is a tabular array of the chemical elements organized by atomic number, from the element with the lowest atomic number, 
	hydrogen, to the element with the highest atomic number, oganesson ");
      }
      else if(i == 2)
      {
       printf("\n Element :- an element is a pure substance consisting only of atoms that all have the same numbers of protons in their nuclei ");
      }
      else if(i == 3)
      {
       printf("\n Atom :- An atom is the smallest unit of ordinary matter that forms a chemical element. Every solid, liquid, gas, and plasma is composed of neutral or ionized 
       atoms.");
      }
       else if(i == 4)
      {
       printf("\n Nucleus :- The atomic nucleus is the small, dense region consisting of protons and neutrons at the center of an atom ");
      }
      else if(i == 5)
      {
       printf("\n Proton :- A proton is a subatomic particle, symbol p or p⁺ , with a positive electric charge of +1e elementary charge and a mass slightly less than that of
       a neutron.");
      }
       else if(i == 6)
      {
       printf("\n Neutron :- The neutron is a subatomic particle, symbol n or n⁰ , which has a neutral charge, and a mass slightly greater than that of a proton.");
      }
       else if(i == 7)
      {
       printf("\n Electron :- The electron is a subatomic particle whose electric charge is negative one elementary charge");
      }
      else if(i == 8)
      {
       printf("\n Energy Level :- The electrons surrounding an atom are located in regions around the nucleus called “energy levels”");
      }
       else if(i == 9)
      {
       printf("\n Orbital :- An orbit in chemistry is the fixed path on which electron moves or revolves around the atom's nucleus");
      }
       else if(i == 10)
      {
       printf("\n Valence Electron :- Valence electrons are the electrons located at the outermost shell of an atom");
      }
      else if(i == 11)
      {
       printf("\n Periods :- The Horizontal rows of the periodic table ");
      }
      else if(i == 12)
      {
       printf("\n Groups :- The vertical columns of the periodic table ");
      }
      else if(i == 13)
      {
       printf("\n Ionisation :- Ionization or ionisation is the process by which an atom or a molecule acquires a negative or positive charge by gaining or losing electrons ");
      }
      else if(i == 14)
      {
       printf("\n Cation :- Cations are positively-charged ions  ");
      }
      else if(i == 15)
      {
       printf("\n Anions :- Anions are negatively-charged ions  ");
      }
      else if(i == 16)
      {
       printf("\n Atomic Number  :- The atomic number or proton number of a chemical element is the number of protons found in the nucleus of every atom of that element");
      }
       else if(i == 17)
      {
       printf("\n Mass Number  :- TThe mass number, also called atomic mass number or nucleon number, is the total number of protons and neutrons in an atomic nucleus");
      }
       else if(i == 18)
      {
       printf("\n Metal  :- A substance with high electrical conductivity, luster, and malleability, which readily loses electrons to form positive ions (cations)");
      }
       else if(i == 19)
      {
       printf("\n Non-Metal  :- a nonmetal is a chemical element that usually gains electrons when reacting with a metal, and which forms an acid if combined with oxygen and 
       hydrogen");
      }
       else if(i == 20)
      {
       printf("\n Metalloid  :- A metalloid is a type of chemical element which has a preponderance of properties in between, or that are a mixture of, those of metals and 
       nonmetals ");
      }
       else if(i == 21)
      {
       printf("\n Alkali Family  :- The alkali metal family is found on the periodic table in Group 1, which is on the far left side of the table");
      }
      else if(i == 22)
      {
       printf("\n Alkali Earth Metal  :- The alkaline earth metals are the second most reactive family of elements");
      }
      else if(i == 23)
      {
       printf("\n Calchogen  :- The chalcogens (ore forming) are the chemical elements in group 16 of the periodic table. This group is also known as the oxygen family.");
      }
       else if(i == 24)
      {
       printf("\n Halogen  :- The halogens are a group in the periodic table consisting of five or six chemically related elements: fluorine, chlorine, bromine, iodine (I), 
       and astatine.");
      }
       else if(i == 25)
      {
       printf("\n Nobel Gas  :- The noble gases make up a class of chemical elements with similar properties; under standard conditions, they are all odorless, colorless, 
       monatomic gases with very low chemical reactivity");
      }
      else if(i == 26)
      {
       printf("\n Isotope  :- Isotopes can be defined as the variants of chemical elements that possess the same number of protons and electrons, but a different number of 
       neutrons ");
      }
      else if(i == 27)
      {
       printf("\n Lanthanide  :- The lanthanide or lanthanoid series of chemical elements comprises the 15 metallic chemical elements with atomic numbers 57–71, from lanthanum 
       through lutetium ");
      }
       else if(i == 28)
      {
       printf("\n Actinides :-  The Actinide series contains elements with atomic numbers 89 to 103 and is in the sixth period and the third group of the periodic table ");
      }
      else if(i == 29)
      {
        exit(0);
      }
    else
    {
       printf("\n Invalid Choice");
       printf("\n Press '0' or 'o' to Continue.. or any key to exit...");
       scanf("%s",&b);
    }
  }while(b == 'o'|| b == '0');
  printf("\n\n Press Any Key To Continue \n");
  getch();
  }
  int history()
  {   
      FILE*filePointer1;
           char dataToBeRead[50];
	      filePointer1 = fopen("history.txt","r");

	   if (filePointer1 == NULL)
	   {
	      printf("\n history.txt file failed to open.");
	      printf("\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	   }
	   else
	   {
	      printf("\n HISTORY OF PERIODIC TABLE ");
	      printf("\n The file is now opened. \n");
	      printf("\n ######################################");

		  while(fgets(dataToBeRead,50,filePointer1) != NULL)
		     {
		        printf("%s",dataToBeRead);
		     }
		     fclose(filePointer1);

		     printf("\n Data successfully read from file history.txt \n");
		     printf("\n ############################################# \n");
		     printf("\n The file in now closed.");
	}
	printf("\n\n Press Any Key To Continue \n");
	getch();
}
int characteristics()
{
  FILE*filePointer2;
           char dataToBeRead[50];
	      filePointer2 = fopen("charas.txt","r");

	   if (filePointer2 == NULL)
	   {
	      printf("\n charas.txt file failed to open.");
	      printf("\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	   }
	   else
	   {
	      printf("\n CHARASTERISTICS OF PERIODIC TABLE ");
	      printf("\n The file is now opened. \n");
	      printf("\n ######################################");

		  while(fgets(dataToBeRead,50,filePointer2) != NULL)
		     {
		        printf("%s",dataToBeRead);
		     }
		     fclose(filePointer2);

		     printf("\n Data successfully read from file charas.txt \n");
		     printf("\n ############################################# \n");
		     printf("\n The file in now closed.");
	}
	printf("\n\n Press Any Key To Continue \n");
	getch();
}
int formulas()
{
  FILE*filePointer3;
           char dataToBeRead[50];
	      filePointer3 = fopen("formulas.txt","r");

	   if (filePointer3 == NULL)
	   {
	      printf("\n formulas.txt file failed to open.");
	      printf("\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	   }
	   else
	   {
	      printf("\n FORMULAS OF PERIODIC TABLE ");
	      printf("\n The file is now opened. \n");
	      printf("\n ######################################");

		  while(fgets(dataToBeRead,50,filePointer3) != NULL)
		     {
		        printf("%s",dataToBeRead);
		     }
		     fclose(filePointer3);

		     printf("\n Data successfully read from file formulas.txt \n");
		     printf("\n ############################################# \n");
		     printf("\n The file in now closed.");
	}
	printf("\n\n Press Any Key To Continue \n");
	getch();
}
int features()
{
  FILE*filePointer4;
           char dataToBeRead[50];
	      filePointer4 = fopen("features.txt","r");

	   if (filePointer4 == NULL)
	   {
	      printf("\n features.txt file failed to open.");
	      printf("\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	   }
	   else
	   {
	      printf("\n FEATURES OF PERIODIC TABLE ");
	      printf("\n The file is now opened. \n");
	      printf("\n ######################################");

		  while(fgets(dataToBeRead,50,filePointer4) != NULL)
		     {
		        printf("%s",dataToBeRead);
		     }
		     fclose(filePointer4);

		     printf("\n Data successfully read from file features.txt \n");
		     printf("\n ############################################# \n");
		     printf("\n The file in now closed.");
	}
	printf("\n\n Press Any Key To Continue \n");
	getch();
}
int atomic_number(void)
{
   int n;
   printf("\n ============================================================== \n");
   printf("\n Enter the Atomic Number you want to search for : ");
   scanf("%d",&n);
   n--;
   if(n>=0 && n<112)
           return n;
   else
           return -1;
}
int atomic_name(void)
{
   char x[20];
   int i,flag = 0;
   printf("\n ============================================================== \n");
   printf("\n Enter the Atomic Name you want to search for : ");
   scanf("%s",&x);
   for(i=0;i<112;i++)
   {
        if(strcmp(x,name[i])==0)
	{
	   flag = 1;
	   break;
	}
   }
   if(flag == 1)
      return i;
   else
      return -1;
 }

 int atomic_symbol(void)
 {
     char x[5];
     int i,flag = 0;
     printf("\n ============================================================== \n");
     printf("\n Enter the Atomic Symbol you want to search for : ");
     scanf("%s",&x);

   for(i=0;i<112;i++)
   {
        if(strcmp(x,symbol[i])==0)
	{
	   flag = 1;
	   break;
	}
   }
   if(flag == 1)
      return i;
   else
      return -1;
 }
 int atomic_weight(void)
 {
   double x;
   int i,flag = 0;
     printf("\n ============================================================== \n");
     printf("\n Enter the Atomic Weight you want to search for : ");
     scanf("%lf",&x);

   for(i=0;i<112;i++)
   {
        if(strcmp(x,weight[i])==x)
	{
	   flag = 1;
	   break;
	}
   }
   if(flag == 1)
      return i;
   else
      return -1;
 }
 char block(int i)
 {
    char ch= ' ';
    int i= i + 1;
     printf("\n ============================================================== \n");
     if(n==1 || n==3 || n==4 || n==11 || n==12 || n==19 || n==20 || n==37 || n==38 || n==55 || n==56 || n==87 || n==88)
		ch = 's';
	else if(n==2 || (n>=5 && n<=10) || (n>=13 && n<=18) || (n>=31 && n<=36) || (n>=49 && n<=54) || (n>=81 && n<=86))
		ch = 'p';
	else if((n>=21 && n<=30) || (n>=39 && n<=48) || (n>=72 && n<=80) || (n>=104 && n<=112))
		ch = 'd';
	else
		ch='f';
	return ch;

 }

 char property(int i)
 {
    int n=i+1;
		char ch=' ';
		printf("\n ============================================================== \n");
		if (n==1 || n==2 || (n>=6 && n<=10) || (n>=15 && n<=18) || (n>=34 && n<=36) || n==53 || n==54 ||n==86)
			ch='n';
		else if (n==5 || n==14 || n==32 || n==33 || n==51 ||n==52 ||n==85)
			ch='s';
		else
			ch='m';
		return ch;
  }
  void show(int i,char ch1,char ch2)
  {
	printf("\n\t\t\t\t\t HERE'S YOUR SEARCH RESULT\n\n");
	printf("\n\t\t\t\t\tAtomic Number     : %d\n",(i+1));
	printf("\t\t\t\t\tAtomic Symbol     : %s\n",symbol[i]);
	printf("\t\t\t\t\tAtomic Name       : %s\n",name[i]);
	printf("\t\t\t\t\tAtomic Weight     : %.2f\n",weight[i]);
	printf("\t\t\t\t\tBlock             : %c\n",ch1);
	printf("\t\t\t\t\tMetallic property : ");
	if (ch2=='n')
		printf("Non-Metal\n");
	else if (ch2=='s')
		printf("Metalloid\n");
	else
		printf("Metal\n");
	printf("\n\t\t\t\t\t\tThank You ! \n\n\n");
}