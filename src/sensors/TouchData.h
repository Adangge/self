/**
* Copyright 2017 IBM Corp. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/


#ifndef TOUCH_DATA_H
#define TOUCH_DATA_H

#include "IData.h"
#include "SelfLib.h"

class SELF_API TouchData : public IData 
{
public:
	RTTI_DECL();

	TouchData()
	{}
	TouchData(const std::string & a_SensorName, float a_fEngaged) : 
		m_SensorName(a_SensorName), 
		m_fEngaged(a_fEngaged)
	{}

	//! ISerializable interface
	virtual void Serialize(Json::Value & json)
	{
		json["m_SensorName"] = m_SensorName;
		json["m_fEngaged"] = m_fEngaged;
	}
	virtual void Deserialize(const Json::Value & json)
	{
		m_SensorName = json["m_SensorName"].asString();
		m_fEngaged = json["m_fEngaged"].asFloat();
	}

	//!Accessors
	const std::string & GetSensorName() const
	{
		return m_SensorName;
	}

	float GetEngaged() const
	{
		return m_fEngaged;
	}

	bool IsEngaged() const
	{
		return m_fEngaged > 0.5f;
	}

private:
	//!Data
	std::string  	m_SensorName;
	float 			m_fEngaged;
};


#endif //TOUCH_DATA_H
