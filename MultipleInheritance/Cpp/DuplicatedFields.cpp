/**
 *
 * @author Dmitry Logvinovich
 * @version 1
 *
 * Illustrates concept of non-virtual inheritance in C++.
 * With non-virtual inheritance there are 2 copise of superclass fields,
 * which is often desirable like in the example below.
 *
 *
 * FileWriter    FileWritter
 *      |             |
 *  Loggable       Sensor    
 *       \           /      
 *        \         /
 *       LoggingSensor 
 */     


class FileWriter
{
    public:
        FileWriter(string fileName) {
            this->fileName = fileName;
        string fileName;
};

class Loggable: public FileWriter
{
    public:
        Loggable(string user, string logFileName): FileWriter(logFileName) {
            this->userName = user;
        }
        string userName;
};

class Sensor: public FileWriter 
{
    public:
        Sensor(string sensorType, string fname): FileWriter(fname) {
        }
};

//in this class we want to have 2 copies fo FileWriter field because
//logging and sensing are two different operations and we woild like to
//document both processes
class LoggingSensor: public Sensor, public FileWriter                    
{
    public:
        LoggingSensor(string user, string logFileName,
                      string sensorType, string logFname):
            Loggable(s)
};

