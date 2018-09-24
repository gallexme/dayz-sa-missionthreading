class MissionThread
{
	CustomMission m_mission;
	string name;
	void Init(CustomMission owner) {
        m_Mission = owner;
    }
	void SetName(string newName) {
		name = newName;
	}
	string GetName() {
		return name;
	}
	void StartThread() {
		
	}
	bool CanRun() {

	}
	void ~MissionScript()
	{
	}
	
	
};
