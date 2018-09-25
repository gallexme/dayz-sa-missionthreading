
#ifndef MISSION_SCRIPT
#define MISSION_SCRIPT

class MissionScriptShared  {



	ref array<EntityAI> zombies;
	ref Counter counter;
	
	/*Class Get(string key ) {
		return m_Data.Get(key);
	}
	void Insert(string key, Class data) {
		m_Data.Insert(key,data);
	}*/
}
class Counter {
	int zombieKills =0;
}
class MissionScriptThread
{
	ref MissionScriptShared m_MissionShared;
	bool m_Running = false;
	ScriptModule m_Self;
	
	string m_Name;
	void Init(ScriptModule self, ref MissionScriptShared owner)
	{
		m_Self = self;
		
		m_MissionShared = owner;
		Print("SELF: ");Print(m_Self);
		Print("owner: ");Print(m_MissionShared);
	}
	void SetName(string newName)
	{
		m_Name = newName;
	}
	string GetName()
	{
		return m_Name;
	}
	MissionScriptShared GetMissionShared()
	{
		return m_MissionShared;
	}
	void StartScript()
	{
		m_Running = true;
		m_Self.Call(this, "ScriptThread", NULL);
	}
	void ScriptThread()
	{
		while (this.CanRun())
		{
			Print("Useless Script");
			Sleep(100);
		}
	}
	void StopScript()
	{
		m_Running = false;
		m_Self.Release();
		delete this;
	}
	bool CanRun()
	{
		return m_Running;
	}
	void ~MissionScriptThread()
	{
		m_Running = false;
	}
};
#endif