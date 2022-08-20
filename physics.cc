#include "physics.hh"

MyPhysicsList :: MyPhysicsList()
{
	//RegisterPhysics(new G4EmStandardPhysics());
	//RegisterPhysics(new G4OpticalPhysics());

}

MyPhysicsList::~MyPhysicsList()
{}

void MyPhysicsList::ConstructParticle()
{
	G4MuonPlus::Definition();
	G4MuonMinus::Definition();
}

void MyPhysicsList::ConstructProcess()
{
	//AddTransportation();
	ConstructEM();
}

void MyPhysicsList::ConstructEM()
{
	G4PhysicsListHelper *ph = G4PhysicsListHelper::GetPhysicsListHelper();
	auto particleIterator=GetParticleIterator();
	particleIterator->reset();

	while((*particleIterator)())
	{
		G4ParticleDefinition *particledef =  particleIterator->value();
			if(particledef == G4MuonPlus::Definition())
		{
			ph->RegisterProcess(new G4MuIonisation(), particledef);
			ph->RegisterProcess(new G4MuBremsstrahlung(), particledef);
			ph->RegisterProcess(new G4MuPairProduction(), particledef);
			ph->RegisterProcess(new G4MuonNuclearProcess(), particledef);
		}

		if(particledef == G4MuonMinus::Definition())
		{
			ph->RegisterProcess(new G4MuIonisation(), particledef);
			ph->RegisterProcess(new G4MuBremsstrahlung(), particledef);
			ph->RegisterProcess(new G4MuPairProduction(), particledef);
			ph->RegisterProcess(new G4MuonNuclearProcess(), particledef);
		}
	}
}
