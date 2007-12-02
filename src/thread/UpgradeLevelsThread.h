/*=============================================================================
XMOTO

This file is part of XMOTO.

XMOTO is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

XMOTO is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with XMOTO; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
=============================================================================*/

#ifndef __UPGRADELEVELSTHREAD_H__
#define __UPGRADELEVELSTHREAD_H__

#include "XMThread.h"
#include "WWWAppInterface.h"

class WebLevels;
class GameState;

class UpgradeLevelsThread : public XMThread, public WWWAppInterface {
public:
  UpgradeLevelsThread(GameState* pCallingState);
  virtual ~UpgradeLevelsThread();

  void setTaskProgress(float p_percent);
  std::string getMsg() const;

  virtual void setBeingDownloadedInformation(const std::string &p_information,bool p_isNew=true);
  virtual void readEvents();
  virtual bool shouldLevelBeUpdated(const std::string &LevelID);

  virtual int realThreadFunction();

private:
  WebLevels*  m_pWebLevels;
  GameState*  m_pCallingState;

  bool m_updateAutomaticallyLevels;
  std::string m_msg;
};

#endif