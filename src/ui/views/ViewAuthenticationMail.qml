/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import QtQuick 2.5
import Mozilla.VPN 1.0
import "../components"
import "../themes/themes.js" as Theme

Item {
    id: viewAuthenticationMail

    VPNMenu {
        id: menu
        objectName: "authenticationMailBackButton"

        title: "Subscribe by Mail"
        isSettingsView: false
        onActiveFocusChanged: if (focus) forceFocus = true
    }

    VPNFlickable {
      anchors.top: menu.bottom
      height: parent.height
      width: parent.width

      VPNPanel {
          id: panel
          logoSize: 70
          height: 270
          logo: "../resources/auth_email.png"
          logoTitle: "Send the PDF and 50$ to:"
          logoSubtitle: "Metal Box Factory\nSuite 441, 4th floor\n30 Great Guildford Street\nLondon\nSE1 0HS"
          anchors.top: parent.top
          anchors.topMargin: 10
      }

      VPNButton {
          id: email

          anchors.top: panel.bottom
          anchors.topMargin: 10

          text: "Generate the PDF to print"
          anchors.horizontalCenterOffset: 0
          anchors.horizontalCenter: parent.horizontalCenter
          radius: 5
          onClicked: VPN.authenticate()

      }

      Text {
          anchors.top: email.bottom
          anchors.topMargin: 10

          text: "When your mail is received, this code and\nthis client will be allowed to use the VPN for 1 year."
          anchors.horizontalCenterOffset: 0
          anchors.horizontalCenter: parent.horizontalCenter
      }
    }
}
