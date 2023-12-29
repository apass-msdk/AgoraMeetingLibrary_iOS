#
# Be sure to run `pod lib lint AgoraMeetingUILibrary.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'AgoraMeetingLibrary_iOS'
  s.version          = '1.11.0.0.2'
  s.summary          = 'A short description of AgoraMeetingLibrary.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/apass-msdk/AgoraMeetingLibrary_iOS'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'winok8' => 'winok8@gmail.com' }
  s.source           = { :git => 'https://github.com/apass-msdk/AgoraMeetingLibrary_iOS.git', :tag => s.version.to_s  }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '13.0'
  s.frameworks = 'UIKit'
  s.requires_arc = true
  s.vendored_frameworks = 'AgoraMeetingKit.xcframework'
  s.dependency  'MJExtension',‘3.2.4'
  s.dependency  'AgoraRtcEngine_Special_iOS', '4.2.3.2'
  s.dependency  'AFNetworking/Serialization',   '4.0.1'
  s.dependency  'AFNetworking/Security',        '4.0.1'
  s.dependency  'AFNetworking/Reachability',    '4.0.1'
  s.dependency  'AFNetworking/NSURLSession',    '4.0.1'
  s.dependency  'SocketRocket','0.6.1'

end
