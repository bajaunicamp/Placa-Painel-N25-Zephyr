#include "can.h"
#include <globals.h>

/*
 * É necessário rodar Init_CAN() e em um loop while rodar CAN_Tick()
 */

LOG_MODULE_REGISTER(can);

struct can_frame botao_frame = {
    .flags = 0, .id = 0xb, .dlc = 8, .data = {1, 2, 3, 4, 5, 6, 7, 8}};

struct can_frame velocimetro_frame = {
    .flags = 0, .id = 0xc, .dlc = 8, .data = {1, 2, 3, 4, 5, 6, 7, 8}};

const struct device *const can_dev = DEVICE_DT_GET(DT_ALIAS(mycan));

struct can_timing timing;

bool mensagem_recebida = false;
static void rx_callback_function(const struct device *dev,
                                 struct can_frame *frame, void *user_data)
{

  if (frame == NULL)
  {
    LOG_ERR("Null frame recebido");
    return;
  }

  if (mensagem_recebida)
  {
    LOG_ERR("Já estamos lidando com uma mensagem, ignorando esta");
  }
  // Tensão da Bateria

  if (frame->id == 0x04 /*Volts*/)
  {
    bateria = (frame->data_32[0] / CONFIG_BATERIA_MAX) * 100;
  }
  // ENND Tensão da Bateria
  //  TPMS
  if (frame->id == 0x07 /* DE, DD*/)
  {
    pneu_de = (frame->data_32[0] / CONFIG_PRESSAO_MAX) * 100;
    pneu_dd = (frame->data_32[1] / CONFIG_PRESSAO_MAX) * 100;
  }
  if (frame->id == 0x08 /* TE, TD*/)
  {
    pneu_te = (frame->data_32[0] / CONFIG_PRESSAO_MAX) * 100;
    pneu_td = (frame->data_32[1] / CONFIG_PRESSAO_MAX) * 100;
  }
  // END TPMS

  mensagem_recebida = true;

  LOG_INF("Recebi a mensagem %d do id %d", frame->data[0], frame->id);
}

// Aceitando todos os CAN
const struct can_filter my_filter = {
    .flags = 0U, .id = 0x000, .mask = CAN_STD_ID_MASK};
int filter_id;

int Init_CAN()
{
  int ret;
  LOG_INF("Inicializando");

  ret = can_set_mode(can_dev, CAN_MODE_NORMAL);
  if (ret != 0)
  {
    printf("Error setting CAN mode [%d]", ret);
    return 0;
  }

  ret = can_set_bitrate(can_dev, 125000);
  if (ret != 0)
  {
    LOG_ERR("Failed to set timing (%d)", ret);
  }

  ret = can_start(can_dev);
  if (ret != 0)
  {
    printf("Error starting CAN controller [%d]", ret);
    return 0;
  }
  filter_id =
      can_add_rx_filter(can_dev, rx_callback_function, NULL, &my_filter);
  if (filter_id < 0)
  {
    LOG_ERR("Unable to add rx filter [%d]", filter_id);
  }

  return 0;
}
