function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Rider_Controls_Full_CAN_Enable"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/CAN Pack"] = {sid: "Rider_Controls_Full_CAN_Enable:92"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:92"] = {rtwname: "<Root>/CAN Pack"};
	this.rtwnameHashMap["<Root>/CAN Pack1"] = {sid: "Rider_Controls_Full_CAN_Enable:98"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:98"] = {rtwname: "<Root>/CAN Pack1"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "Rider_Controls_Full_CAN_Enable:99"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:99"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Data Type Conversion"] = {sid: "Rider_Controls_Full_CAN_Enable:93"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:93"] = {rtwname: "<Root>/Data Type Conversion"};
	this.rtwnameHashMap["<Root>/Data Type Conversion1"] = {sid: "Rider_Controls_Full_CAN_Enable:94"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:94"] = {rtwname: "<Root>/Data Type Conversion1"};
	this.rtwnameHashMap["<Root>/Data Type Conversion2"] = {sid: "Rider_Controls_Full_CAN_Enable:95"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:95"] = {rtwname: "<Root>/Data Type Conversion2"};
	this.rtwnameHashMap["<Root>/Data Type Conversion3"] = {sid: "Rider_Controls_Full_CAN_Enable:96"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:96"] = {rtwname: "<Root>/Data Type Conversion3"};
	this.rtwnameHashMap["<Root>/Data Type Conversion4"] = {sid: "Rider_Controls_Full_CAN_Enable:100"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:100"] = {rtwname: "<Root>/Data Type Conversion4"};
	this.rtwnameHashMap["<Root>/Data Type Conversion5"] = {sid: "Rider_Controls_Full_CAN_Enable:104"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:104"] = {rtwname: "<Root>/Data Type Conversion5"};
	this.rtwnameHashMap["<Root>/InHardware"] = {sid: "Rider_Controls_Full_CAN_Enable:77"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:77"] = {rtwname: "<Root>/InHardware"};
	this.rtwnameHashMap["<Root>/OutHardware"] = {sid: "Rider_Controls_Full_CAN_Enable:84"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:84"] = {rtwname: "<Root>/OutHardware"};
	this.rtwnameHashMap["<Root>/Software"] = {sid: "Rider_Controls_Full_CAN_Enable:55"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:55"] = {rtwname: "<Root>/Software"};
	this.rtwnameHashMap["<Root>/eCAN Transmit"] = {sid: "Rider_Controls_Full_CAN_Enable:97"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:97"] = {rtwname: "<Root>/eCAN Transmit"};
	this.rtwnameHashMap["<Root>/eCAN Transmit1"] = {sid: "Rider_Controls_Full_CAN_Enable:101"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:101"] = {rtwname: "<Root>/eCAN Transmit1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
