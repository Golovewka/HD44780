#ifdef HD44780_H_
#define HD44780_H_

    #include <stdint.h>

    // Перечень команд
    #define CLEAR_DISPLAY_CLEAR_DISPLAY                     0x01
    #define RETURN_HOME_RETURN_HOME                         0x02
    #define ENTRY_MODE_SET_CURSOR_MOVE_DIRECTION_INCREMENT  0x06
    #define ENTRY_MODE_SET_CURSOR_MOVE_DIRECTION_DISCREMENT 0x04
    #define ENTRY_MODE_SET_SPECIFIES_DISPLAY_SHIFT_ENABLE   0x05
    #define ENTRY_MODE_SET_SPECIFIES_DISPLAY_SHIFT_DISABLE  0x04
    #define DISPLAY_CONTROL_CURSOR_BLINK_DISABLE            0x08
    #define DISPLAY_CONTROL_CURSOR_BLINK_ENABLE             0x09
    #define DISPLAY_CONTROL_CURSOR_DISABLE                  0x08
    #define DISPLAY_CONTROL_CURSOR_ENABLE                   0x0A
    #define DISPLAY_CONTROL_DISPLAY_DISABLE                 0x08
    #define DISPLAY_CONTROL_DISPLAY_ENABLE                  0x0C
    #define DISPLAY_SHIFT_SHIFT_LEFT                        0x10
    #define DISPLAY_SHIFT_SHIFT_RIGHT                       0x14
    #define DISPLAY_SHIFT_SHIFT_CURSOR                      0x10
    #define DISPLAY_SHIFT_HIFT_DISPLAY                      0x18
    #define FUNCTION_SET_CHARACTERS_FONT_5X8                0x20
    #define FUNCTION_SET_CHARACTERS_FONT_5X10               0x24
    #define FUNCTION_SET_DISPLAY_LINE_1_LINE                0x20
    #define FUNCTION_SET_DISPLAY_LINE_2_LINE                0x28
    #define FUNCTION_SET_INTERFACE_DATA_LENGHT_4_BIT        0x20
    #define FUNCTION_SET_INTERFACE_DATA_LENGHT_8_BIT        0x30

    class hd44780
    {
        private:
            
            uint8_t clear_display;
            uint8_t return_home;
            uint8_t entry_mode_set;
            uint8_t display_control;
            uint8_t display_shift;
            uint8_t function_set;
            uint8_t cgram_address;
            uint8_t ddram_addres;

        public:

            uint8_t pin_init (pin_t hd44780_pin, port_t host_port, pin_t host_pin);
            uint8_t write_port (uint8_t value);
            uint8_t write_instruction (uint8_t instruction);
            uint8_t read_port (void);
            uint8_t init (void);
            uint8_t clear_display (void);
            uint8_t return_home (void);
            uint8_t set_cursor_move_direction (uint8_t direction);
            uint8_t set_specifies_cursor_shift (uint8_t cursor_shift);
            uint8_t set_display_state (uint8_t state);
            uint8_t set_cursor_state (uint8_t state);
            uint8_t set_cursor_blink_state (uint8_t state);
            uint8_t shift_display (uint8_t direction);
            uint8_t shift_cursor (uint8_t direction);
            uint8_t set_cursor_position (uint8_t roll, uint8_t column);
            uint8_t print_char (char character);
            uint8_t print_text (char *text);

    };
    

#endif // HD44780_H_