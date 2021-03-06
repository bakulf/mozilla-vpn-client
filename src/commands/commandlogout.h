/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef COMMANDLOGOUT_H
#define COMMANDLOGOUT_H

#include "command.h"

class CommandLogout final : public Command {
 public:
  explicit CommandLogout(QObject* parent);
  ~CommandLogout();

  int run(QStringList& tokens) override;
};

#endif  // COMMANDLOGOUT_H
