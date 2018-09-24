#include "mpmissions/dayzOffline.chernarusplus/scripts/MissionThread.c"
 
class WorkerMissionThread : MissionThread
{
void StartThread() {
		while(CanRun()) {

        }
}
	
	
};

MissionThread CreateMissionThread()
{
	return new WorkerMissionThread;
}
