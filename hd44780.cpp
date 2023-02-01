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
 */
uint8_t hd44780::write_pin(port_t &port, pin_t pin_t)
{


    
}