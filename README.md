# STM32_MODBUS_lib
`
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	
	
	
	HAL_TIM_Base_Stop_IT(&htim1);
	htim1.Instance->CNT=0;
	data[data_resive_namber]=data_resive[0];	
	data_resive_namber++;
	HAL_UART_Receive_IT(&huart1,data_resive,1);
	HAL_TIM_Base_Start_IT(&htim1);
	
	
  UNUSED(huart);

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	
	
		HAL_TIM_Base_Stop_IT(&htim1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,1);
		if(client_modbus(0x01,data,8,modbus_register,data_send_modbus,&data_send_modbus_len)){
		HAL_UART_Transmit(&huart1,data_send_modbus,data_send_modbus_len,256);}
		data_resive_namber=0;
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,0);
		memset(data,0,256);
		HAL_UART_Receive_IT(&huart1,data_resive,1);
	//	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_0);
		
}
`