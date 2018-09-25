#include "mpmissions/dayzOffline.chernarusplus/scripts/MissionScript.c"

#ifndef MISSION_Script_WORKER
#define MISSION_Script_WORKER

class ControlMissionScriptThread : MissionScriptThread
{
	void ScriptThread()
	{
		while (this.CanRun())
		{
			Print("Check Zombies");
			CheckZombies();
			Print("Where The Magic Happens");
			Sleep(1000);
		}
	}
	void CheckZombies()
	{
		
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);
		foreach (EntityAI zombie : this.GetMissionShared().zombies)
		{
			
		}
		
	}
	
	
}
;
static ref MissionScriptThread mod_missionScript;
void  CreateMissionScript(Param3<ScriptModule,MissionScriptShared,string> data)
{
	mod_missionScript = new ControlMissionScriptThread;
	mod_missionScript.Init(data.param1,data.param2);
	mod_missionScript.SetName(data.param3);
	mod_missionScript.StartScript();
}
void StopMissionScript()
{
	mod_missionScript.StopScript();
}
#endif