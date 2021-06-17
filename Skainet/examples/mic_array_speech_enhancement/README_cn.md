# 降噪例程 [[English]](./README.md)

（参考在上一级的 `examples` 目录下的 [README.md](../README.md) 文件来获取更多信息。）

本示例使用乐鑫麦克风阵列语音增强（mic-array speech enhancement, MASE）算法处理多通道语音信号，输出单通道 16kHz 16bit 信号，并通过耳机输出增强后的信号。开发板的 "Mode" 按键用于控制输出信号是否经过 MASE 算法，其他按键用于控制 LED 灯的状态。同时，增强后的信号输入乐鑫唤醒识别引擎 WakeNet 和本地命令词识别引擎 MultiNet，您也可以通过语音来控制 LED 灯的状态。

## 如何使用例程

### 准备硬件

* 本示例能够在 ESP32-Korvo 开发板上运行。更多信息请参考 [ESP32-Korvo 用户指南](https://github.com/espressif/esp-skainet/blob/master/docs/esp32-korvo-guide/docs/zh_CN/hw-reference/esp32/user-guide-esp32-korvo-v1.1.md)。

* 耳机。

### 配置工程

* 进入 `idf.py menuconfig`。

* 在 `Serial flasher config` 菜单中设置串口信息。

* 在 `Audio Media HAL` 菜单的 `Audio hardware board` 选项中选择 Korvo，并根据需要选择 `Mic-array type`。

### 编译和烧写

编译并烧写，然后运行终端监控查看打印：

```
idf.py flash monitor
```

(退出窗口，请键入 ``Ctrl-]``.)

参考 [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/stable/get-started-cmake/index.html) 来获取更多使用 ESP-IDF 编译项目的细节。

### 使用按键功能

ESP32-Korvo 有 6 个按键：`MODE`、`PLAY`、`SET`、`VOL+`、`VOL-` 和 `REC`。在本例程中，`MODE` 用于设置输出信号是否经过 MASE 算法，其他案件用于控制 LED 灯的状态。

命令行的初始打印是：

```
MASE STATE: 1
```

说明 MASE 处于开启状态。按下 "Mode" 按键，MASE 会关闭，且命令行输出：

```
MASE STATE: 0
```

再按下 "Mode" 按键即可重新开启 MASE。

其他按键和 LED 灯状态的对应关系如下：

|按键|设备反馈|
|:- |:- |
|PLAY|打开 RGB LED，显示白色。|
|SET|打开 RGB LED，显示红色。|
|VOL+|打开 RGB LED，显示黄色。|
|VOL-|打开 RGB LED，显示蓝色。|
|REC|熄灭 RGB LED。|

### 使用唤醒和命令词识别功能

上电后，您可使用默认唤醒词“嗨，乐鑫”唤醒开发板。唤醒后，板载的 12 个 RGB LED 将被循环点亮为白色，表示设备正在等待命令词。

本例程支持使用命令词控制 LED 灯的状态，对应关系如下：

|命令词|设备反馈|
|:- |:- |
|打开白灯|打开 RGB LED，显示白色。|
|打开红灯|打开 RGB LED，显示红色。|
|打开黄灯|打开 RGB LED，显示黄色。|
|打开蓝灯|打开 RGB LED，显示蓝色。|
|关闭电灯|熄灭 RGB LED。|

## 例程输出

### 音频流

开发者可以直接通过耳机听到输出音频信号，也可以保存 MASE 前后的音频信号，使用音频分析软件更直观地看到语音增强效果。本例程中 MASE 工作在 `WAKE_UP_ENHANCEMENT_MODE` 模式，即针对唤醒词（及其之后用于本地命令词识别或云端语音识别的语音信号，若有）做了特殊的增强处理。一个 2-mic MASE 输入输出对比示例如下图所示，唤醒词得到了明显增强：

* 时域

![MASE_td](MASE_td.png)

* 频域

![MASE_fd](MASE_fd.png)

### 语音识别效果的提升

MASE 能够显著提高语音识别效果，包括本地唤醒词识别（WakeNet），本地命令词识别（MultiNet）和云端识别。我们的测试结果显示，5dB 信噪比环境下，和单麦系统相比，2 麦和 3 麦分别能够提升超过 **15%** 和 **20%** 的 WakeNet 性能和超过 **10%** 和 **15%** 的 MultiNet 性能。