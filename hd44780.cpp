#include "hd44780.h"

/*
 * @brief Функция запуска таймера в мкс
 *
 * @note В данную функцию необходимо поместить реализацию таймера,
 * характерного для вашей системы
 * 
 * @param time время работы таймера
 * 
 * @return Возвращает статус работы команды
 * @retval STATUS_IDLE начало конфигурации таймера
 * @retval STATUS_OK таймер завершил свою работу корректно
 * @retval STATUS_BUSY таймер считает
 * @retval STATUS_ERROR таймер преждевремено завершил свою работу
 */
uint8_t hd44780::timer_us(uint16_t time)
{

    uint8_t status = STATUS_IDLE;

    //Далее необходимо расположить реализацию таймера

    return(status);

}

/*
 * @brief Функция запуска таймера в мс
 *
 * @note В данную функцию необходимо поместить реализацию таймера,
 * характерного для вашей системы
 * 
 * @param time время работы таймера
 * 
 * @return Возвращает статус работы команды
 * @retval STATUS_IDLE начало конфигурации таймера
 * @retval STATUS_OK таймер завершил свою работу корректно
 * @retval STATUS_BUSY таймер считает
 * @retval STATUS_ERROR таймер преждевремено завершил свою работу
 */
uint8_t hd44780::timer_ms(uint16_t time)
{

    uint8_t status = STATUS_IDLE;

    // Далее необходимо расположить реализацию таймера

    return(status);

}

/*
 * @brief Функция записи значения в пин
 * 
 * @param port наименования порта
 * @param pin номер пина (битовая маска)
 * 
 * @return статус записи в пин
 * @retval STATUS_OK
 * @retvak STATUS_ERROR
 */
uint8_t hd44780::write_pin(port_t &port, pin_t pin)
{

    // Далее необходимо расположить реализацию функции записи в пин
    
}

/*
 * @brief Функция чтения значения на пине
 *
 * @param port наименование порта
 * @param pin номер пина
 * 
 * @return значение на пине (бит маску)
 */
uint8_t hd44780::read_pin(port_t &port, pin_t pin)
{

	// Далее необходимо расположить реализацию функции чтения пина

}

/*
 * @brief Функция смены режима работы пина, вход->выход и наоборот
 *
 * @param port наименование порта
 * @param pin номер пина
 * @param mode режим работы (0 - вход, 1 - выход)
 * 
 * @return статус выполнения операции
 * @retval STATUS_OK
 */
uint8_t hd44780::switch_pin_mode(port_t &port, pin_t pin, uint8_t mode)
{

	// Далее необходимо расположить реализацию функции

}

/*
 * @brief Функция инициализации пинов для работы с дисплеем
 *
 * @param hd44780_port наименование порта на котором находится нога дисплея
 * @param hd44780_pin наименование пина дисплея (битовая маска)
 * @param port наименование порта микроконтроллера
 * @param pin наименование пина микроконтроллера (битовая маска)
 * 
 * @return статус инициализации портов
 * @retval STATUS_OK
 */
uint8_t hd44780::init_pin(port_t &hd44780_port, pin_t hd44780_pin, port_t &port, pin_t pin)
{

    hd44780_port = port;
    hd44780_pin = pin;
    return(STATUS_OK);

}

/*
 * @brief Функция записи значения в порт (линии данных) дисплея
 *
 * @param value значение записываемое в порт
 * 
 * @return статус записи в порт
 * @retval STATUS_OK 
 */
uint8_t hd44780::write_port(uint8_t value)
{

	if (value & 0x01) write_pin(*d0_port, d0_pin);
	else write_pin(*d0_port, ~d0_pin);
		
	if (value & 0x02) write_pin(*d1_port, d1_pin);
	else write_pin(*d1_port, ~d1_pin);
		
	if (value & 0x04) write_pin(*d2_port, d2_pin);
	else write_pin(*d2_port, ~d2_pin);
		
	if (value & 0x08) write_pin(*d3_port, d3_pin);
	else write_pin(*d3_port, ~d3_pin);
		
	if (value & 0x10) write_pin(*d4_port, d4_pin);
	else write_pin(*d4_port, ~d4_pin);
		
	if (value & 0x20) write_pin(*d5_port, d5_pin);
	else write_pin(*d5_port, ~d5_pin);
		
	if (value & 0x40) write_pin(*d6_port, d6_pin);
	else write_pin(*d6_port, ~d6_pin);
		
	if (value & 0x80) write_pin(*d7_port, d7_pin);
	else write_pin(*d7_port, ~d7_pin);

    return(STATUS_OK);
			
}

/*
 * @brief Функция записи инструкции в дисплей
 *
 * @param instruction инструкция для дисплея
 * 
 * @return статус операции
 * @retval STATUS_OK
 */
uint8_t hd44780::write_instruction(uint8_t instruction)
{

    write_pin(*rs_port, ~rs_pin);
	write_pin(*rw_port, ~rw_pin);
	write_port(instruction);
	write_pin(*en_port, en_pin);
	timer_us(1);
	write_pin(*en_port, ~en_pin);
	timer_us(100);

    return(STATUS_OK);

}

/*
 * @brief Функция чтения порта дисплея
 * 
 * @return значение на порте
 */
uint8_t hd44780::read_port(void)
{

    uint8_t value = 0;
	
	// Смена портов с выходов на вход
	switch_pin_mode(*d0_port,d0_pin, 0);
	switch_pin_mode(*d1_port,d1_pin, 0);
	switch_pin_mode(*d2_port,d2_pin, 0);
	switch_pin_mode(*d3_port,d3_pin, 0);
	switch_pin_mode(*d4_port,d4_pin, 0);
	switch_pin_mode(*d5_port,d5_pin, 0);
	switch_pin_mode(*d6_port,d6_pin, 0);
	switch_pin_mode(*d7_port,d7_pin, 0);
			
	// Чтение значения
	write_pin(*rs_port, ~rs_pin);
	write_pin(*rw_port, rw_pin);
	write_pin(*en_port, en_pin);
	timer_us(1);
	write_pin(*en_port, ~en_pin);
	timer_us(100);
		
	if (read_pin(*d0_port, d0_pin)) value |= 0x01;
	if (read_pin(*d1_port, d1_pin)) value |= 0x02;
	if (read_pin(*d2_port, d2_pin)) value |= 0x04;
	if (read_pin(*d3_port, d3_pin)) value |= 0x08;
	if (read_pin(*d4_port, d4_pin)) value |= 0x10;
	if (read_pin(*d5_port, d5_pin)) value |= 0x20;
	if (read_pin(*d6_port, d6_pin)) value |= 0x40;
	if (read_pin(*d7_port, d7_pin)) value |= 0x80;
	
	// Смена портов с выходов на выход
	switch_pin_mode(*d0_port,d0_pin, 1);
	switch_pin_mode(*d1_port,d1_pin, 1);
	switch_pin_mode(*d2_port,d2_pin, 1);
	switch_pin_mode(*d3_port,d3_pin, 1);
	switch_pin_mode(*d4_port,d4_pin, 1);
	switch_pin_mode(*d5_port,d5_pin, 1);
	switch_pin_mode(*d6_port,d6_pin, 1);
	switch_pin_mode(*d7_port,d7_pin, 1);
			
	return(value);

}

/*
 * @brief Функция установки курсора на экране
 *
 * @param roll номер строки
 * @param column номер столбца
 * 
 * @return статус операции
 * @retval STATUS_OK
 * @retval STATUS_IDLE
 * @retval STATUS_ERROR
 */
uint8_t hd44780::set_cursor(uint8_t roll, uint8_t column)
{

	if (roll == 0)
	{
		
		write_instruction(0x80 | (column + ROLL0_ADDR));
		while(read_port() & 0x80);
		
	}
	else
	{
		
		write_instruction(0x80 | (column + ROLL1_ADDR));
		while(read_port() & 0x80);
		
	}

}

/*
 * @brief Функция инициализации дисплея
 */
uint8_t hd44780::init (void)
{

	uint8_t status = STATUS_IDLE;
	
	_delay_ms(15);
	function_set = FUNCTION_SET_INTERFACE_DATA_LENGHT_8_BIT;
	write_instruction(function_set);
	timer_ms(5);
	write_instruction(function_set);
	timer_us(100);
	write_instruction(function_set);
	timer_ms(1);
	function_set = FUNCTION_SET_DISPLAY_LINE_2_LINE | FUNCTION_SET_CHARACTERS_FONT_5X10 | FUNCTION_SET_INTERFACE_DATA_LENGHT_8_BIT;
	write_instruction(function_set);
	while(read_port() & 0x80);
	display_control = DISPLAY_CONTROL_DISPLAY_ENABLE | DISPLAY_CONTROL_CURSOR_BLINK_ENABLE;
	write_instruction(display_control);
	while(read_port() & 0x80);
	write_cmd(CLEAR_DISPLAY_CLEAR_DISPLAY);
	while(read_port() & 0x80);
	entry_mode_set = ENTRY_MODE_SET_CURSOR_MOVE_DIRECTION_INCREMENT;
	write_instruction(entry_mode_set);
	display_shift = DISPLAY_SHIFT_SHIFT_CURSOR | DISPLAY_SHIFT_SHIFT_RIGHT;
	write_instruction(display_shift);
	set_cursor(0,0);
	
	status = STATUS_OK;
	
	return(status); 

}