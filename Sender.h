#pragma once
#include "DEVSim.h"
#include "message_def.h"
#include "engine_def.h"

class CSender : public CAtomic
{
public:
	CSender(int sender_id);
	~CSender();

public:
	virtual bool ExtTransFn(const CDEVSimMessage & _msg);
	virtual bool IntTransFn();
	virtual bool OutputFn(CDEVSimMessage & _msg);
	virtual TimeType TimeAdvanceFn();

	//status
public:
	enum SysState { WAIT, DECIDED };
	SysState m_state;

	int m_sender_id;

public:
	//add ports(string)
	static std::string inport_dec;
	static std::string outport_hum_road;
	static std::string outport_taxi_road;
	static std::string outport_prev_collector;


public:
	RoadInfo* cur_road_info;
	CellOrder* humanOrder;
	CellOrder* taxiOrder;
};

