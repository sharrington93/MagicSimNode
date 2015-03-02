function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Rider_Controls_InHardware_CAN_Enable"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "Rider_Controls_InHardware_CAN_Enable:78"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:78"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/CAN Pack"] = {sid: "Rider_Controls_InHardware_CAN_Enable:59"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:59"] = {rtwname: "<Root>/CAN Pack"};
	this.rtwnameHashMap["<Root>/CAN Recv"] = {sid: "Rider_Controls_InHardware_CAN_Enable:78"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:78"] = {rtwname: "<Root>/CAN Recv"};
	this.rtwnameHashMap["<Root>/Display"] = {sid: "Rider_Controls_InHardware_CAN_Enable:83"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:83"] = {rtwname: "<Root>/Display"};
	this.rtwnameHashMap["<Root>/Display1"] = {sid: "Rider_Controls_InHardware_CAN_Enable:86"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:86"] = {rtwname: "<Root>/Display1"};
	this.rtwnameHashMap["<Root>/Software"] = {sid: "Rider_Controls_InHardware_CAN_Enable:55"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:55"] = {rtwname: "<Root>/Software"};
	this.rtwnameHashMap["<Root>/eCAN Transmit"] = {sid: "Rider_Controls_InHardware_CAN_Enable:62"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:62"] = {rtwname: "<Root>/eCAN Transmit"};
	this.rtwnameHashMap["<S1>/CAN Configuration"] = {sid: "Rider_Controls_InHardware_CAN_Enable:77"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:77"] = {rtwname: "<S1>/CAN Configuration"};
	this.rtwnameHashMap["<S1>/CAN Receive"] = {sid: "Rider_Controls_InHardware_CAN_Enable:79"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:79"] = {rtwname: "<S1>/CAN Receive"};
	this.rtwnameHashMap["<S1>/CAN Unpack"] = {sid: "Rider_Controls_InHardware_CAN_Enable:80"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:80"] = {rtwname: "<S1>/CAN Unpack"};
	this.rtwnameHashMap["<S1>/Terminator"] = {sid: "Rider_Controls_InHardware_CAN_Enable:81"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:81"] = {rtwname: "<S1>/Terminator"};
	this.rtwnameHashMap["<S1>/RPM"] = {sid: "Rider_Controls_InHardware_CAN_Enable:82"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:82"] = {rtwname: "<S1>/RPM"};
	this.rtwnameHashMap["<S1>/Throttle %"] = {sid: "Rider_Controls_InHardware_CAN_Enable:85"};
	this.sidHashMap["Rider_Controls_InHardware_CAN_Enable:85"] = {rtwname: "<S1>/Throttle %"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
