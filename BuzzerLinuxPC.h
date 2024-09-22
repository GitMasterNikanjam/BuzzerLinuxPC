#ifndef _BUZZER_H_
#define _BUZZER_H_

// ################################################################
// Include libraries:

    #include <iostream>
    #include <fcntl.h>
    #include <unistd.h>
    #include <linux/kd.h>
    #include <sys/ioctl.h>
    #include <chrono>
    #include <thread>

// #####################################################################
// Buzzer class:

    // Active buzzer object.
    class Buzzer
    {
        public:

            struct BuzzerParameters
            {
                // Note frequency. [Hz]
                uint16_t NOTE_FRQ;

                /**
                 * Programmable Interval Timer (PIT): The PIT is an older timer chip used in PCs to generate precise timing intervals. 
                 * It operates at a base frequency of 1.193180 MHz (or 1193180 Hz).
                 */
                uint32_t PIT;
            }parameters;

            // Last error accured.
            std::string errorMessage;

            /*
                Buzzer object constructor. Not apply setting.
                Hint: begin() method needs after this for apply setting on hardware.
            */
            Buzzer(); 

            /*
                Apply setting on hardware. Start Buzzer action.
                @return true if successed.
            */
            bool begin(void);

            /*
                Clean setting on hardware. Stop  Buzzer action. 
            */
            void clean(void);

            /*
                Alaram for warning type 1.
                Hint: it excutes in blocking mode.
            */
            void alarmWarning_1(void);

            /*
                Alarm for initialization actions.
                Hint: it excutes in blocking mode.
            */
            void alarmInit(void);

            /*
                Alarm for exite/stop actions.
                Hint: it excutes in blocking mode.
            */
            void alarmExit(void);

            void on(void);

            void off();

            void sleep(uint32_t value);

        private:

            int console_fd;

    };

#endif  // _BUZZER_H_