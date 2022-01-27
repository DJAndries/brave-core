// Copyright (c) 2021 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

#include "brave/browser/ui/webui/brave_vpn/vpn_panel_handler.h"

#include <utility>

VPNPanelHandler::VPNPanelHandler(
    mojo::PendingReceiver<brave_vpn::mojom::PanelHandler> receiver,
    ui::MojoBubbleWebUIController* webui_controller)
    : receiver_(this, std::move(receiver)),
      webui_controller_(webui_controller) {}

VPNPanelHandler::~VPNPanelHandler() = default;

void VPNPanelHandler::ShowUI() {
  auto embedder = webui_controller_->embedder();
  // TODO(bsclifton): trigger a loading state for the panel?
  // how to reach the VPN service to call `SetPurchasedState`?
  // can this call methods using the receiver?
  if (embedder) {
    LOG(ERROR) << "BSC]] ShowUI";
    embedder->ShowUI();
  }
}

void VPNPanelHandler::CloseUI() {
  // NOTE(bsclifton): this never seems to get called
  LOG(ERROR) << "BSC]] CloseUI 1";
  auto embedder = webui_controller_->embedder();
  if (embedder) {
    LOG(ERROR) << "BSC]] CloseUI 2";
    embedder->CloseUI();
  }
}
