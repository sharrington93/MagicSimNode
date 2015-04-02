function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Rider_Controls_Control_CAN_Enable"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/CAN Pack"] = {sid: "Rider_Controls_Control_CAN_Enable:59"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:59"] = {rtwname: "<Root>/CAN Pack"};
	this.rtwnameHashMap["<Root>/CAN Pack1"] = {sid: "Rider_Controls_Control_CAN_Enable:79"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:79"] = {rtwname: "<Root>/CAN Pack1"};
	this.rtwnameHashMap["<Root>/CAN Pack2"] = {sid: "Rider_Controls_Control_CAN_Enable:85"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:85"] = {rtwname: "<Root>/CAN Pack2"};
	this.rtwnameHashMap["<Root>/CAN Pack3"] = {sid: "Rider_Controls_Control_CAN_Enable:88"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:88"] = {rtwname: "<Root>/CAN Pack3"};
	this.rtwnameHashMap["<Root>/CAN Unpack"] = {sid: "Rider_Controls_Control_CAN_Enable:75"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:75"] = {rtwname: "<Root>/CAN Unpack"};
	this.rtwnameHashMap["<Root>/CAN Unpack1"] = {sid: "Rider_Controls_Control_CAN_Enable:78"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:78"] = {rtwname: "<Root>/CAN Unpack1"};
	this.rtwnameHashMap["<Root>/CAN Unpack2"] = {sid: "Rider_Controls_Control_CAN_Enable:81"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:81"] = {rtwname: "<Root>/CAN Unpack2"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "Rider_Controls_Control_CAN_Enable:90"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:90"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Data Type Conversion"] = {sid: "Rider_Controls_Control_CAN_Enable:87"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:87"] = {rtwname: "<Root>/Data Type Conversion"};
	this.rtwnameHashMap["<Root>/Software"] = {sid: "Rider_Controls_Control_CAN_Enable:55"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:55"] = {rtwname: "<Root>/Software"};
	this.rtwnameHashMap["<Root>/Terminator"] = {sid: "Rider_Controls_Control_CAN_Enable:76"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:76"] = {rtwname: "<Root>/Terminator"};
	this.rtwnameHashMap["<Root>/Terminator1"] = {sid: "Rider_Controls_Control_CAN_Enable:82"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:82"] = {rtwname: "<Root>/Terminator1"};
	this.rtwnameHashMap["<Root>/Terminator2"] = {sid: "Rider_Controls_Control_CAN_Enable:84"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:84"] = {rtwname: "<Root>/Terminator2"};
	this.rtwnameHashMap["<Root>/eCAN Receive"] = {sid: "Rider_Controls_Control_CAN_Enable:74"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:74"] = {rtwname: "<Root>/eCAN Receive"};
	this.rtwnameHashMap["<Root>/eCAN Receive1"] = {sid: "Rider_Controls_Control_CAN_Enable:77"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:77"] = {rtwname: "<Root>/eCAN Receive1"};
	this.rtwnameHashMap["<Root>/eCAN Receive2"] = {sid: "Rider_Controls_Control_CAN_Enable:83"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:83"] = {rtwname: "<Root>/eCAN Receive2"};
	this.rtwnameHashMap["<Root>/eCAN Transmit"] = {sid: "Rider_Controls_Control_CAN_Enable:62"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:62"] = {rtwname: "<Root>/eCAN Transmit"};
	this.rtwnameHashMap["<Root>/eCAN Transmit1"] = {sid: "Rider_Controls_Control_CAN_Enable:80"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:80"] = {rtwname: "<Root>/eCAN Transmit1"};
	this.rtwnameHashMap["<Root>/eCAN Transmit2"] = {sid: "Rider_Controls_Control_CAN_Enable:86"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:86"] = {rtwname: "<Root>/eCAN Transmit2"};
	this.rtwnameHashMap["<Root>/eCAN Transmit3"] = {sid: "Rider_Controls_Control_CAN_Enable:89"};
	this.sidHashMap["Rider_Controls_Control_CAN_Enable:89"] = {rtwname: "<Root>/eCAN Transmit3"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
