void main()
{

}
class CustomMission: MissionServer
{	
	ScriptModule			m_ThreadManager;
	Class m_RunThread;
	int zedKillCount = 0;

	void CustomMission() {
		StartWorker();
		
	}
	void StartWorker() {
		if(m_ThreadManager) {
			delete m_RunThread;
			KillThread( m_ThreadManager,"CreateWorker");
			m_ThreadManager.Release();
		}
		string	file_name;
		int 	file_attr;
		int		flags;
		TStringArray  missionList = new TStringArray;
		
			string m_PathToMissions = "mpmissions";
			
			string path_find_pattern = m_PathToMissions+"\\*"; //*/
			FindFileHandle file_handler = FindFile(path_find_pattern, file_name, file_attr, flags);
			
			bool found = true;
			while ( found )
			{				
				if ( file_attr & FileAttr.DIRECTORY )
				{
					Print(file_name)
					missionList.Insert(file_name);
				}
				
				found = FindNextFile(file_handler, file_name, file_attr);
			}
			
			foreach(string  mission : missionList)
			{
				
				m_ThreadManager = ScriptModule.LoadScript(MissionScript,"mpmissions"+"/"+mission+"/scripts/worker.c",true);
				Print("mpmissions"+"/"+mission+"/worker.c");
				Print(m_ThreadManager);
				if(m_ThreadManager) {
					break;
				}
			}
		if(m_ThreadManager)
		{
			
			m_RunThread = new Class;
			m_ThreadManager.Call(NULL, "CreateWorker", new Param3<ref Class, ref array <EntityAI>, ref ScriptCallQueue> (m_RunThread,m_Zombies,m_Queue));	
		}
	}



	
};

  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}