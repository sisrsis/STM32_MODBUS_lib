```
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "modbuslib.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint8_t data_resive[2];
uint8_t data[256];
uint8_t data_resive_namber;

uint16_t modbus_register[20];
uint8_t data_send_modbus[256];
uint8_t data_send_modbus_len;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

HAL_TIM_Base_Stop_IT(&htim1);
htim1.Instance->CNT=0;
data[data_resive_namber]=data_resive[0];	
data_resive_namber++;
HAL_UART_Receive_IT(&huart1,data_resive,1);
HAL_TIM_Base_Start_IT(&htim1);
UNUSED(huart);

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	HAL_TIM_Base_Stop_IT(&htim1);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
	if(client_modbus(0x01,data,8,modbus_register,data_send_modbus,&data_send_modbus_len)){
	HAL_UART_Transmit(&huart1,data_send_modbus,data_send_modbus_len,256);}
	data_resive_namber=0;
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
	HAL_UART_Receive_IT(&huart1,data_resive,1);

} 
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
	HAL_UART_Receive_IT(&huart1,data_resive,1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		
		
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
```
