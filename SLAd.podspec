#
# Be sure to run `pod lib lint SLAd.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'SLAd'
  s.version          = '0.4.0'
  s.summary          = '一个测试cocoapods'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/lslliushilin/SLAd'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { '刘士林' => 'shilin.liu@domob.cn' }
  s.source           = { :git => 'https://github.com/lslliushilin/SLAd.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '10.0'

  s.source_files = 'SLAd/Classes/**/*'
  
  # s.resource_bundles = {
  #   'SLAd' => ['SLAd/Assets/*.png']
  # }

   s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
   s.dependency 'AFNetworking', '~> 2.3'
  # 确保使用frameworks
  s.source_files = 'MyFramework/Classes/**/*'
    
  s.frameworks = 'UIKit', 'Foundation'
 
    # 如果你的库依赖于其他pods，在这里指定它们
#  s.dependency 'AFNetworking', '~> 3.0'
  s.static_framework = true
#  s.vendored_frameworks = 'SLAd/Classes/DMAdSDK.framework'
  s.resource_bundles = {
     'DMAdSDK_Bundle' => ['DMAdSDK_Bundle/Assets/*.png', 'SLAd/Classes/DMAdSDK_Bundle.bundle']
   }
end
