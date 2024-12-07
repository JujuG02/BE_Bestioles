#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include "Kamikaze.h"
#include "Sensor.h"
#include "BestioleCreator.h"

#include <iostream>

using namespace std;

//example of configurations
void basicConfig(Aquarium *ecosysteme, BestioleCreator *creator);
void basicNageoire(Aquarium *ecosysteme, BestioleCreator *creator);
void peureuseOreille(Aquarium *ecosysteme, BestioleCreator *creator);
void peureuseYeux(Aquarium *ecosysteme, BestioleCreator *creator);
void kamikazeWithGodCarapace(Aquarium *ecosysteme, BestioleCreator *creator);
void gregaireOreille(Aquarium *ecosysteme, BestioleCreator *creator);
void prevoyanteVsPeureuse(Aquarium *ecosysteme, BestioleCreator *creator);
void godCamouflage(Aquarium *ecosysteme, BestioleCreator *creator);
void fullStuff(Aquarium *ecosysteme, BestioleCreator *creator);

int main()
{

   Aquarium ecosysteme(640, 480, 30);

   BestioleCreator* creator = new BestioleCreator();

   //choose an example configuration or make your own
   //basicConfig(&ecosysteme, creator);
   //basicNageoire(&ecosysteme, creator);
   //peureuseOreille(&ecosysteme, creator);
   //peureuseYeux(&ecosysteme, creator);
   kamikazeWithGodCarapace(&ecosysteme, creator);
   //gregaireOreille(&ecosysteme, creator);
   //prevoyanteVsPeureuse(&ecosysteme, creator);
   //godCamouflage(&ecosysteme, creator);
   //fullStuff(&ecosysteme, creator);

   ecosysteme.run();

   delete creator;
   return 0;
}

void basicConfig(Aquarium *ecosysteme, BestioleCreator *creator)
{
   //25 basic blind bestioles
   Peureuse *pe = new Peureuse();

   for (int i = 1; i <= 25; ++i)
   {
      Bestiole *c = creator->createBasic(pe);
      ecosysteme->getMilieu().addMember(c);
   }

   delete pe;
}

void basicNageoire(Aquarium *ecosysteme, BestioleCreator *creator)
{
   //25 basic blind bestioles with nageoire (multiple behavior)
   for (int i = 1; i <= 25; ++i)
   {
      Bestiole *c = creator->createNageoireMB();
      ecosysteme->getMilieu().addMember(c);
   }

}

void peureuseOreille(Aquarium *ecosysteme, BestioleCreator *creator)
{
   //5 peureuse bestioles with oreille
   Peureuse *pe = new Peureuse();

   for (int i = 1; i <= 5; ++i)
   {
      Bestiole *c = creator->createOreille(pe);
      ecosysteme->getMilieu().addMember(c);
   }

   delete pe;
}

void peureuseYeux(Aquarium *ecosysteme, BestioleCreator *creator)
{
   //5 peureuse bestioles with yeux
   Peureuse *pe = new Peureuse();

   for (int i = 1; i <= 5; ++i)
   {
      Bestiole *c = creator->createYeuxCustom(nullptr, 100, 1., 2., 10000, false, pe);
      ecosysteme->getMilieu().addMember(c);
   }
}

void kamikazeWithGodCarapace(Aquarium *ecosysteme, BestioleCreator *creator)
{
   //1 kamikaze with unbreakable carapace vs 15 basic bestioles
   Kamikaze *ka = new Kamikaze();
   Peureuse *pe = new Peureuse();

   for (int i = 1; i <= 16; ++i)
   {
      Bestiole *c;
      if(i==1)
      {
         c = creator->createCarapaceCustom(nullptr, 0., 0.7, 10000, false, ka);
         c = creator->createOreilleCustom(c, 100, 1, 10000, false, ka);

      }
      else
         c = creator->createBasic(pe);

      ecosysteme->getMilieu().addMember(c);
   }

   delete ka;
   delete pe;
}

void gregaireOreille(Aquarium *ecosysteme, BestioleCreator *creator)
{
   //6 gregaire bestioles with oreille
   Gregaire *gr = new Gregaire();

   for (int i = 1; i <= 6; ++i)
   {
      Bestiole *c = creator->createOreille(gr);
      ecosysteme->getMilieu().addMember(c);
   }

   delete gr;
}

void prevoyanteVsPeureuse(Aquarium *ecosysteme, BestioleCreator *creator)
{
   //1 prevoyante bestiole vs 5 peureuse bestioles
   Prevoyante *pr = new Prevoyante();
   Peureuse *pe = new Peureuse();

   for (int i = 1; i <= 6; ++i)
   {
      Bestiole *c;
      if(i==1)
         c = creator->createOreilleCustom(nullptr, 100, 1, 10000, false, pr);
      else
         c = creator->createOreilleCustom(nullptr, 100, 1, 10000, false, pe);

      ecosysteme->getMilieu().addMember(c);
   }

   delete pr;
   delete pe;
}

void godCamouflage(Aquarium *ecosysteme, BestioleCreator *creator)
{
   //1 undetectable bestiole vs 2 kamikaze bestioles
   Kamikaze *ka = new Kamikaze();
   Peureuse *pe = new Peureuse();

   for (int i = 1; i <= 3; ++i)
   {
      Bestiole *c;
      if(i==1)
      {
         c = creator->createCamouflageCustom(nullptr, 0., 10000, false, pe);
         c = creator->createOreilleCustom(c, 100, 1., 10000, false, pe);
      }
      else
         c = creator->createOreilleCustom(nullptr, 100, 1., 10000, false, ka);  

      ecosysteme->getMilieu().addMember(c);
   }

   delete ka;
   delete pe;
}

void fullStuff(Aquarium *ecosysteme, BestioleCreator *creator)
{
   //full stuffed bestioles with multiple behaviors
   //not the most intresting because of unpredictable results

   for (int i = 1; i <= 3; ++i)
   {
      Bestiole* c = creator->createFullMB();  

      ecosysteme->getMilieu().addMember(c);
   }
}

