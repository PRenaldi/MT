#ifndef PHYSICS_HH
#define PHYSICS_HH

//#include "G4VModularPhysicsList.hh"
//#include "G4EmStandardPhysics.hh"
//#include "G4OpticalPhysics.hh"
//#include "G4RadioactiveDecayPhysics.hh"
//#include "G4DecayPhysics.hh"
#include "G4VUserPhysicsList.hh" 
#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"
#include "G4MuonNuclearProcess.hh"
#include "G4PhysicsListHelper.hh"


class MyPhysicsList : public G4VUserPhysicsList
{
public:
	MyPhysicsList();
	~MyPhysicsList();

	void ConstructParticle();
	void ConstructProcess();

	//void AddTransportation();
	void ConstructEM();
};


#endif
