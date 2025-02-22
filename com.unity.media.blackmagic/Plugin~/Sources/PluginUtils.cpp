#include "PluginUtils.h"

namespace MediaBlackmagic
{
    static const std::string k_FileName = "/Blackmagic_Log.log";
    static std::string k_DefinitiveFilePath = "C:/Blackmagic/Debug_BMD.txt";

    void WriteFileDebug(const char* const message, const bool append)
    {
#ifdef DEBUG_LOG
        std::ofstream myfile;
        
        if (append)
        {
            myfile.open(k_DefinitiveFilePath, std::ios_base::app | std::ios_base::out);
        }
        else
        {
            myfile.open(k_DefinitiveFilePath);
        }

        myfile << message;
        myfile.close();
#endif
    }

    void WriteFileDebug(const char* const message, int value, const bool append)
    {
#ifdef DEBUG_LOG
        std::ofstream myfile;

        if (append)
        {
            myfile.open(k_DefinitiveFilePath, std::ios_base::app | std::ios_base::out);
        }
        else
        {
            myfile.open(k_DefinitiveFilePath);
        }

        myfile << message << value << "\n";
        myfile.close();
#endif
    }

    void WriteFileDebug(const char* const message, unsigned long long value, const bool append)
    {
#ifdef DEBUG_LOG
        std::ofstream myfile;

        if (append)
        {
            myfile.open(k_DefinitiveFilePath, std::ios_base::app | std::ios_base::out);
        }
        else
        {
            myfile.open(k_DefinitiveFilePath);
        }

        myfile << message << value << "\n";
        myfile.close();
#endif
    }
}
