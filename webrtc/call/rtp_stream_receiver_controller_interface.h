/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#ifndef WEBRTC_CALL_RTP_STREAM_RECEIVER_CONTROLLER_INTERFACE_H_
#define WEBRTC_CALL_RTP_STREAM_RECEIVER_CONTROLLER_INTERFACE_H_

#include <memory>

#include "webrtc/call/rtp_packet_sink_interface.h"

namespace webrtc {

// An RtpStreamReceiver is responsible for the rtp-specific but
// media-independent state needed for receiving an RTP stream.
// TODO(nisse): Currently, only owns the association between ssrc and
// the stream's RtpPacketSinkInterface. Ownership of corresponding
// objects from modules/rtp_rtcp/ should move to this class (or
// rather, the corresponding implementation class). We should add
// methods for getting rtp receive stats, and for sending RTCP
// messages related to the receive stream.
class RtpStreamReceiverInterface {
 public:
  virtual ~RtpStreamReceiverInterface() {}
};

// This class acts as a factory for RtpStreamReceiver objects.
class RtpStreamReceiverControllerInterface {
 public:
  virtual ~RtpStreamReceiverControllerInterface() {}

  virtual std::unique_ptr<RtpStreamReceiverInterface> CreateReceiver(
      uint32_t ssrc,
      RtpPacketSinkInterface* sink) = 0;
  // For registering additional sinks, needed for FlexFEC.
  virtual void AddSink(uint32_t ssrc, RtpPacketSinkInterface* sink) = 0;
  virtual size_t RemoveSink(const RtpPacketSinkInterface* sink) = 0;
};

}  // namespace webrtc

#endif  // WEBRTC_CALL_RTP_STREAM_RECEIVER_CONTROLLER_INTERFACE_H_
